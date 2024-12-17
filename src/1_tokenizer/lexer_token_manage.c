/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_manage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:52:03 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 00:58:02 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lexer.h"
#include "libft.h"

t_token make_token(t_token_type type, const char *val)
{
	t_token tk;

	tk.type = type;
	tk.value = NULL;
	if (val)
		tk.value = ft_strdup(val);
	return (tk);
}

static void free_token(void *ct)
{
	t_token *t;

	t = (t_token *)ct;
	if (t)
	{
		free(t->value);
		free(t);
	}
}

t_list *token_list_add(t_list *lst, t_token tk)
{
	t_token *dup;
	t_list *new;

	dup = malloc(sizeof(t_token));
	if (!dup)
		return (ft_lstclear(&lst, free_token), NULL);
	*dup = tk;
	new = ft_lstnew(dup);
	if (!new)
	{
		free_token(dup);
		ft_lstclear(&lst, free_token);
		return (NULL);
	}
	ft_lstadd_back(&lst, new);
	return (lst);
}

t_token *token_list_finalize(t_list *lst)
{
	t_token *arr;
	t_list *tmp;
	int size;
	int i;

	size = ft_lstsize(lst);
	arr = malloc(sizeof(t_token) * (size + 1));
	if (!arr)
		return (ft_lstclear(&lst, free_token), NULL);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		arr[i] = *(t_token *)tmp->data;
		i++;
		tmp = tmp->next;
	}
	arr[i].type = TT_EOF;
	arr[i].value = NULL;
	ft_lstclear(&lst, free_token);
	return (arr);
}

void free_tokens(t_token *tokens)
{
	int i;

	i = 0;
	while (tokens && tokens[i].type != TT_EOF)
	{
		free(tokens[i].value);
		i++;
	}
	free(tokens);
}
