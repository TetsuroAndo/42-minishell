/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:44:20 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 12:27:23 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LEXER_H
#define LEXER_H

#include "minishell.h"
#include <stddef.h>

typedef enum e_token_type
{
	TT_CMD,
	TT_PIPE,
	TT_REDIRECT_IN,
	TT_REDIRECT_OUT,
	TT_APPEND,
	TT_HEREDOC,
	TT_EOF,
	TT_ERROR
} t_token_type;

typedef struct s_token
{
	t_token_type type;
	char *value;
} t_token;

typedef struct s_lexer
{
	const char *input;
	size_t pos;
} t_lexer;

/**
 * @brief メインのトークナイズ関数
 * 入力文字列を解析し、t_token*配列（NULL終端）を返す
 * 返却後、使用者がfreeする
 */
t_token *lexer(const char *input);

void free_tokens(t_token *tokens);

#endif