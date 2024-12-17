/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:55:37 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 19:56:08 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include <ctype.h>

void	skip_spaces(t_lexer *lx)
{
	while (lx->input[lx->pos] && isspace((unsigned char)lx->input[lx->pos]))
		lx->pos++;
}

int	is_special_char(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

char	peek_char(t_lexer *lx)
{
	return (lx->input[lx->pos]);
}

char	advance_char(t_lexer *lx)
{
	char	c;

	c = lx->input[lx->pos];
	if (c != '\0')
		lx->pos++;
	return (c);
}
