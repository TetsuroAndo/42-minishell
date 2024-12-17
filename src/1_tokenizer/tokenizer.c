/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:53:32 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 01:06:42 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lexer.h"
#include "libft.h"

static void init_lexer(t_lexer *lx, const char *input)
{
	lx->input = input;
	lx->pos = 0;
}

/* lexerは入力文字列を受け取り、トークン(t_list*)を返す */
t_list *lexer(const char *input)
{
	t_lexer lx;
	t_list *tokens;

	init_lexer(&lx, input);
	tokens = lexer_loop(&lx);
	return (tokens);
}
