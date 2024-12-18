/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:39:45 by teando            #+#    #+#             */
/*   Updated: 2024/12/19 01:45:35 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * トークンリスト（cmd_tokenリスト）を扱いやすくするためのヘルパー。
 */
t_cmd_token	*get_next_cmd_token(t_list **cur)
{
	t_cmd_token	*tk;

	if (!cur || !*cur)
		return (NULL);
	tk = (t_cmd_token *)(*cur)->data;
	*cur = (*cur)->next;
	return (tk);
}
