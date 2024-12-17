/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:53:09 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 00:53:11 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lexer.h"
#include "libft.h"

static t_list *handle_special_char(t_lexer *lx, t_list *ts)
{
	char c;
	t_token_type tp;

	c = lx->input[lx->pos];
	lx->pos++;
	if (c == '|')
		tp = TT_PIPE;
	else
		tp = check_redirect_type(lx, c);
	ts = token_list_add(ts, make_token(tp, NULL));
	return (ts);
}

static t_list *handle_word(t_lexer *lx, t_list *ts)
{
	char *w;

	w = read_word(lx);
	if (!w)
		return (add_error_token(ts));
	ts = token_list_add(ts, make_token(TT_CMD, w));
	free(w);
	return (ts);
}

t_list *lexer_loop(t_lexer *lx)
{
	t_list *ts;

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
	return (ts);
}
