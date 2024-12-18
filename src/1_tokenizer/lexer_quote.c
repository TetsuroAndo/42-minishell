/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:52:34 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 18:01:57 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char	*read_quoted_word(t_lexer *lx, char quote)
{
	size_t	start;
	char	*res;

	start = lx->pos;
	while (lx->input[lx->pos] && lx->input[lx->pos] != quote)
		lx->pos++;
	if (!lx->input[lx->pos])
		return (NULL);
	res = ft_substr(lx->input, start, lx->pos - start);
	lx->pos++;
	return (res);
}
