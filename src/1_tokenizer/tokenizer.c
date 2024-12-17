/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:53:32 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 00:53:35 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lexer.h"
#include "libft.h"

static void init_lexer(t_lexer *lx, const char *input)
{
	lx->input = input;
	lx->pos = 0;
}

t_token *lexer(const char *input)
{
	t_lexer lx;
	t_list *tokens;
	t_token *arr;

	init_lexer(&lx, input);
	tokens = lexer_loop(&lx);
	if (!tokens)
		return (NULL);
	arr = token_list_finalize(tokens);
	return (arr);
}
