/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:52:34 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 19:05:15 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

/**
 * @brief  クォート文字列を読み込み、内容を string として返す
 * @detail  LX からクォート文字列を読み込み、内容を string として返す
 *          クォート文字列が閉じられていない場合は NULL を返す
 *          クォート文字列が閉じられた場合は、その内容を string として返す
 * @param  lx  トークン生成器
 * @param  quote  クォート文字
 * @return  クォート文字列の内容を string として返す
 */
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
