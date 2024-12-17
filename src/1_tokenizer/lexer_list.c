/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:56:58 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 19:57:03 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_token	*token_list_add(t_token *list, size_t *count, t_token newtok)
{
	t_token	*res;

	res = realloc(list, sizeof(t_token) * (*count + 2));
	if (!res)
	{
		free(newtok.value);
		return (list);
	}
	res[*count] = newtok;
	*count = *count + 1;
	res[*count] = (t_token){TT_EOF, NULL};
	return (res);
}
