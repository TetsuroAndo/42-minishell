/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_manage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:52:03 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 18:02:02 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_token	make_token(t_token_type type, const char *val)
{
	t_token	tk;

	tk.type = type;
	tk.value = NULL;
	if (val)
		tk.value = ft_strdup(val);
	return (tk);
}

void	free_token(void *ct)
{
	t_token	*t;

	t = (t_token *)ct;
	if (t)
	{
		free(t->value);
		free(t);
	}
}

t_list	*token_list_add(t_list *lst, t_token tk)
{
	t_token	*dup;
	t_list	*new;

	dup = malloc(sizeof(t_token));
	if (!dup)
	{
		ft_lstclear(&lst, free_token);
		return (NULL);
	}
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
