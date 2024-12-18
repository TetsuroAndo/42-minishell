/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:53:09 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 19:04:45 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "libft.h"

/**
 * @brief  リダイレクトタイプを判定する
 * @detail
 *    文字列 lx から現在位置の次の文字を読み取り、first と次の文字の組み合わせに基づいて
 *    適切なリダイレクトタイプ(TT_HEREDOC, TT_APPEND, TT_REDIRECT_IN, TT_REDIRECT_OUT)を返す。
 *    first が '<' の場合、次の文字が '<' なら TT_HEREDOC を返し、そうでなければ TT_REDIRECT_IN を返す。
 *    first が '>' の場合、次の文字が '>' なら TT_APPEND を返し、そうでなければ TT_REDIRECT_OUT を返す。
 * @param  lx  トークン生成器
 * @param  first  現在位置のリダイレクト文字
 * @return  判定されたリダイレクトトークンタイプ
 */
static t_token_type	check_redirect_type(t_lexer *lx, char first)
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

/**
 * @brief  スペシャル文字をトークン化する
 * @detail  LX からスペシャル文字を読み込み、それを TT_PIPE, TT_AND_AND, TT_OR_OR,
 *          TT_LPAREN, TT_RPAREN, TT_REDIRECT_IN, TT_REDIRECT_OUT, TT_APPEND
 *          のいずれかで ts に追加する
 *          読み込みに失敗した場合は TT_ERROR トークンを追加しておく
 * @param  lx  トークン生成器
 * @param  ts  トークン列
 * @return  ts
 */
static t_list	*handle_special_char(t_lexer *lx, t_list *ts)
{
	char	c;

	c = lx->input[lx->pos++];
	if (c == '|')
	{
		if (lx->input[lx->pos] == '|')
			return (token_list_add(ts, make_token(TT_OR_OR, NULL)), lx->pos++,
				ts);
		return (token_list_add(ts, make_token(TT_PIPE, NULL)));
	}
	if (c == '&')
	{
		if (lx->input[lx->pos] == '&')
			return (token_list_add(ts, make_token(TT_AND_AND, NULL)), lx->pos++,
				ts);
		return (add_error_token(ts));
	}
	if (c == '(')
		return (token_list_add(ts, make_token(TT_LPAREN, NULL)));
	if (c == ')')
		return (token_list_add(ts, make_token(TT_RPAREN, NULL)));
	return (token_list_add(ts, make_token(check_redirect_type(lx, c), NULL)));
}

/**
 * @brief  単語をトークン化する
 * @detail  LX から単語を読み込み、それを TT_CMD トークンとして ts に追加する
 *          読み込みに失敗した場合は TT_ERROR トークンを追加しておく
 * @param  lx  トークン生成器
 * @param  ts  トークン列
 * @return  トークン列
 */
static t_list	*handle_word(t_lexer *lx, t_list *ts)
{
	char	*w;

	w = read_word(lx);
	if (!w)
		return (add_error_token(ts));
	ts = token_list_add(ts, make_token(TT_CMD, w));
	free(w);
	return (ts);
}

/**
 * @brief  トークン列を生成する
 * @detail  LX からトークン列を生成し、返す
 *          生成に失敗した場合は NULL を返す
 *          生成に成功した場合は TT_EOF トークンを追加しておく
 * @param  lx  トークン生成器
 * @return  トークン列
 */
t_list	*lexer_loop(t_lexer *lx)
{
	t_list	*ts;

	ts = NULL;
	skip_spaces(lx);
	while (lx->input[lx->pos])
	{
		if (is_special_char(lx->input[lx->pos]))
			ts = handle_special_char(lx, ts);
		else if (!ft_isspace((unsigned char)lx->input[lx->pos]))
			ts = handle_word(lx, ts);
		if (!ts)
			return (NULL);
		skip_spaces(lx);
	}
	/* 終了トークン(TT_EOF)を追加しておくと便利な場合はここで追加 */
	ts = token_list_add(ts, make_token(TT_EOF, NULL));
	return (ts);
}
