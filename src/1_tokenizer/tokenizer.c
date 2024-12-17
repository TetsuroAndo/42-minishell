/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:10:00 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 20:03:29 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

/*
** _lexer関数を小さい関数に分割
** 例として、init、loop、finalizeなどに分ける
*/
static t_token	*lexer_loop(t_lexer *lx)
{
	t_token			*tokens;
	size_t			count;
	char			c;
	t_token_type	ttype;
	char			*w;

	tokens = malloc(sizeof(t_token));
	tokens[0].type = TT_EOF;
	tokens[0].value = NULL;
	count = 0;
	skip_spaces(lx);
	while (lx->input[lx->pos])
	{
		if (is_special_char(lx->input[lx->pos]))
		{
			c = advance_char(lx);
			ttype = TT_PIPE;
			if (c != '|')
				ttype = check_redirect_type(lx, c);
			tokens = token_list_add(tokens, &count, make_token(ttype, NULL));
		}
		else if (!isspace((unsigned char)lx->input[lx->pos]))
		{
			w = read_word(lx);
			if (!w)
			{
				tokens = token_list_add(tokens, &count, make_token(TT_ERROR,
							NULL));
				break ;
			}
			tokens = token_list_add(tokens, &count, make_token(TT_CMD, w));
			free(w);
		}
		skip_spaces(lx);
	}
	return (tokens);
}

t_token	*lexer(const char *input)
{
	t_lexer	lx;
	t_token	*tokens;

	lx.input = input;
	lx.pos = 0;
	tokens = lexer_loop(&lx);
	return (tokens);
}
