/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:57:03 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 19:41:00 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include <dirent.h>
#include <fnmatch.h>

static t_list	*create_cmd_token_list_from_matches(char **matches)
{
	t_list	*lst;
	t_token	tk;
	int		i;

	lst = NULL;
	i = 0;
	while (matches[i])
	{
		tk = make_token(TT_CMD, matches[i]);
		lst = token_list_add(lst, tk);
		if (!lst)
		{
			return (NULL);
		}
		i++;
	}
	return (lst);
}

static char	**append_match(char **res, size_t count, const char *new_str,
		t_info *info)
{
	char	**new_res;
	size_t	j;

	new_res = (char **)xmalloc(sizeof(char *) * (count + 2), info);
	j = 0;
	while (j < count)
	{
		new_res[j] = res[j];
		j++;
	}
	new_res[count] = ft_strdup(new_str);
	new_res[count + 1] = NULL;
	if (res)
		free(res);
	return (new_res);
}

static char	**wildcard_match(const char *pattern, t_info *info)
{
	DIR				*dir;
	struct dirent	*ent;
	char			**res;
	size_t			count;

	res = NULL;
	count = 0;
	dir = opendir(".");
	if (!dir)
		return (NULL);
	ent = readdir(dir);
	while (ent)
	{
		if (fnmatch(pattern, ent->d_name, 0) == 0)
		{
			res = append_match(res, count, ent->d_name, info);
			if (!res)
			{
				closedir(dir);
				return (NULL);
			}
			count++;
		}
		ent = readdir(dir);
	}
	closedir(dir);
	return (res);
}

static void	replace_current_node(t_list **tokens, t_list *cur, t_list *expanded)
{
	t_list	*prev;
	t_list	*next;
	t_list	*tail;
	t_list	*p;

	next = cur->next;
	prev = NULL;
	p = *tokens;
	while (p && p != cur)
	{
		prev = p;
		p = p->next;
	}
	ft_lstdelone(cur, free_token);
	if (prev)
		prev->next = expanded;
	else
		*tokens = expanded;
	tail = expanded;
	while (tail && tail->next)
		tail = tail->next;
	if (tail)
		tail->next = next;
}

static void	expand_wildcard_at_node(t_list **tokens, t_list **cur, t_info *info)
{
	t_token	*tk;
	char	**matches;
	t_list	*expanded;

	tk = (t_token *)(*cur)->data;
	if (tk->type == TT_CMD && tk->value && ft_strchr(tk->value, '*'))
	{
		matches = wildcard_match(tk->value, info);
		if (matches && matches[0] != NULL)
		{
			expanded = create_cmd_token_list_from_matches(matches);
			ft_strs_clear(matches);
			if (expanded)
			{
				replace_current_node(tokens, *cur, expanded);
				*cur = expanded;
				return ;
			}
		}
		if (matches)
			ft_strs_clear(matches);
	}
}

void	expand_wildcards(t_list **tokens, t_info *info)
{
	t_list	*cur;
	t_list	*next;

	cur = *tokens;
	while (cur)
	{
		next = cur->next;
		expand_wildcard_at_node(tokens, &cur, info);
		cur = next;
	}
}
