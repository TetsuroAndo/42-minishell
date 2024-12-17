/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_redirect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:51:46 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 00:51:46 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lexer.h"

t_token_type check_redirect_type(t_lexer *lx, char first)
{
	char next;

	next = lx->input[lx->pos];
	if (first == '<' && next == '<')
	{
		lx->pos++;
		return (TT_HEREDOC);
	}
	if (first == '>' && next == '>')
	{
		lx->pos++;
		return (TT_APPEND);
	}
	if (first == '<')
		return (TT_REDIRECT_IN);
	return (TT_REDIRECT_OUT);
}
