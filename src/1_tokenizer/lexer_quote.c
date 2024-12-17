/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:57:14 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 19:57:24 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char	*read_quoted_word(t_lexer *lx, char quote_char)
{
	size_t	start;
	size_t	length;
	char	*res;

	start = lx->pos;
	while (lx->input[lx->pos] && lx->input[lx->pos] != quote_char)
		lx->pos++;
	if (!lx->input[lx->pos])
		return (NULL);
	length = lx->pos - start;
	lx->pos++;
	res = ft_substr(lx->input, start, length);
	return (res);
}
