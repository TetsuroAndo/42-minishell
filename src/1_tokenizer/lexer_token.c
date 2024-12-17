/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:56:39 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 19:56:48 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_token	make_token(t_token_type type, const char *value)
{
	t_token	tok;

	tok.type = type;
	tok.value = NULL;
	if (value)
		tok.value = strdup(value);
	return (tok);
}

t_token_type	check_redirect_type(t_lexer *lx, char first)
{
	char	next;

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
