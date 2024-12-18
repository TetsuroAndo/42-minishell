/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:53:09 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 18:34:39 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "libft.h"

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
