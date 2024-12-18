/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_read_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:52:21 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 19:07:07 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

/**
 * @brief      2つの文字列を結合し、新しい文字列を返します。
 * @param      orig  結合する最初の文字列。関数内で解放されます。
 * @param      add   結合する2番目の文字列。関数内で解放されます。
 * @return     結合された新しい文字列。メモリ確保に失敗した場合は NULL を返します。
 * @note       この関数では、引数として渡された文字列のメモリを解放します。
 *             呼び出し元は返り値のメモリを解放する必要があります。
 */
static char	*append_str(char *orig, char *add)
{
	char	*tmp;

	tmp = ft_strjoin(orig, add);
	free(orig);
	free(add);
	return (tmp);
}

/**
 * @brief      LX から通常の単語を読み込み、文字列として返す
 * @param      lx  トークン生成器
 * @return     読み込まれた通常の単語
 * LX から通常の単語を読み込み、それを新しい文字列として返す
 * 単語はスペースや特殊文字が出現するまで読み込む
 * 文字列の末尾に達した場合は、1文字の \0 文字列を返す
 * LX の位置は、単語の次の文字を指すように更新される
 */
static char	*read_normal_segment(t_lexer *lx)
{
	size_t	start;
	char	*seg;

	start = lx->pos;
	while (lx->input[lx->pos] && !ft_isspace((unsigned char)lx->input[lx->pos])
		&& lx->input[lx->pos] != '"' && lx->input[lx->pos] != '\''
		&& !is_special_char(lx->input[lx->pos]))
		lx->pos++;
	seg = ft_substr(lx->input, start, lx->pos - start);
	return (seg);
}

/**
 * @brief  単語を読み取り、文字列を返す
 * @detail  LX からスペシャル文字や空白文字以外の文字列を 1 つずつ読み取り、
 *          連結して文字列を生成する
 *          連結に失敗した場合は NULL を返す
 *          生成に成功した場合は文字列を返す
 * @param  lx  トークン生成器
 * @return  読み取られた文字列
 */
char	*read_word(t_lexer *lx)
{
	char	*word;
	char	*part;
	char	q;

	word = ft_strdup("");
	if (!word)
		return (NULL);
	while (lx->input[lx->pos] && !ft_isspace((unsigned char)lx->input[lx->pos])
		&& !is_special_char(lx->input[lx->pos]))
	{
		if (lx->input[lx->pos] == '"' || lx->input[lx->pos] == '\'')
		{
			q = lx->input[lx->pos++];
			part = read_quoted_word(lx, q);
			if (!part)
				return (free(word), NULL);
			word = append_str(word, part);
		}
		else
			word = append_str(word, read_normal_segment(lx));
		if (!word)
			return (NULL);
	}
	if (word[0] == '\0')
		return (free(word), NULL);
	return (word);
}
