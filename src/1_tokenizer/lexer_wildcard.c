/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:57:03 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 18:08:46 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include <dirent.h>
#include <fnmatch.h>

static t_list	*create_cmd_token_list_from_matches(char **matches)
{
	t_list	*lst;
	t_token	tk;

	lst = NULL;
	for (int i = 0; matches[i]; i++)
	{
		tk = make_token(TT_CMD, matches[i]);
		lst = token_list_add(lst, tk);
	}
	return (lst);
}

static char	**wildcard_match(const char *pattern, t_info *info)
{
	DIR				*dir;
	struct dirent	*ent;
	char			**res;
	size_t			count;
	char			**new_res;

	res = NULL;
	count = 0;
	(void)info;
	dir = opendir(".");
	if (!dir)
		return (NULL);
	while ((ent = readdir(dir)) != NULL)
	{
		if (fnmatch(pattern, ent->d_name, 0) == 0)
		{
			new_res = malloc(sizeof(char *) * (count + 2));
			if (!new_res)
			{
				closedir(dir);
				ft_strs_clear(res);
				return (NULL);
			}
			if (res)
			{
				ft_memcpy(new_res, res, sizeof(char *) * count);
				free(res);
			}
			new_res[count] = ft_strdup(ent->d_name);
			new_res[count + 1] = NULL;
			res = new_res;
			count++;
		}
	}
	closedir(dir);
	return (res);
}

void	expand_wildcards(t_list **tokens, t_info *info)
{
	t_list	*cur;
	t_token	*tk;
	char	**matches;
	t_list	*expanded;
	t_list	*next;
	t_list	*prev;
	t_list	*tail;

	cur = *tokens;
	while (cur)
	{
		tk = (t_token *)cur->data;
		if (tk->type == TT_CMD && tk->value && ft_strchr(tk->value, '*'))
		{
			matches = wildcard_match(tk->value, info);
			if (matches && matches[0] != NULL)
			{
				expanded = create_cmd_token_list_from_matches(matches);
				ft_strs_clear(matches);
				// curノードをexpandedに置き換える
				next = cur->next;
				// リンクリストでcurを削除しexpandedを挿入
				{
					prev = NULL;
					for (t_list *p = *tokens; p && p != cur; p = p->next)
						prev = p;
					ft_lstdelone(cur, free_token);
					if (prev)
						prev->next = expanded;
					else
						*tokens = expanded;
					// expanded末尾へnextをつなぐ
					tail = expanded;
					while (tail->next)
						tail = tail->next;
					tail->next = next;
					cur = next;
					continue ;
				}
			}
			if (matches)
				ft_strs_clear(matches);
		}
		cur = cur->next;
	}
}
