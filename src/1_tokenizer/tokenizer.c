/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:53:32 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 22:03:38 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static void	init_lexer(t_lexer *lx, const char *input)
{
	lx->input = input;
	lx->pos = 0;
}

static t_list	*lexer(const char *input)
{
	t_lexer	lx;
	t_list	*tokens;

	init_lexer(&lx, input);
	tokens = lexer_loop(&lx);
	return (tokens);
}

t_status	xlexer(t_info *info)
{
	t_list		*tokens;
	t_status	st;

	if (!info->source_line)
		return (E_NONE);
	tokens = lexer(info->source_line);
	if (!tokens)
		return (E_NONE);
	expand_wildcards(&tokens, info);
	st = convert_tokens_to_cmd_tokens(tokens, info);
	ft_lstclear(&tokens, free_token);
	return (st);
}
