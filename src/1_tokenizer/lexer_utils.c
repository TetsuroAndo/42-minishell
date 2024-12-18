/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:52:58 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 20:06:25 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	skip_spaces(t_lexer *lx)
{
	while (lx->input[lx->pos] && ft_isspace((unsigned char)lx->input[lx->pos]))
		lx->pos++;
}

int	is_special_char(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '(' || c == ')' || c == '&')
		return (1);
	return (0);
}

int	is_token_special(t_token_type type)
{
	return (type == TT_PIPE || type == TT_REDIRECT_IN || type == TT_REDIRECT_OUT
		|| type == TT_APPEND || type == TT_HEREDOC || type == TT_AND_AND
		|| type == TT_OR_OR || type == TT_LPAREN || type == TT_RPAREN);
}
