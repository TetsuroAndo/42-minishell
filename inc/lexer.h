/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:44:20 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 16:03:40 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"
# include <stddef.h>

typedef enum e_token_type
{
	TT_CMD,          // コマンドトークン
	TT_PIPE,         // パイプ
	TT_REDIRECT_IN,  // 入力リダイレクト
	TT_REDIRECT_OUT, // 出力リダイレクト
	TT_APPEND,       // 追記リダイレクト
	TT_HEREDOC,      // ヒアドキュメント
	TT_EOF,          // 終端
	TT_ERROR         // エラー
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}					t_token;

typedef struct s_cmd_token
{
	t_token_type type; // CMD or PIPEなど
	char *path;        // 実行するコマンド(e.g. "echo")
	char **args;       // 引数列(e.g. {"echo", "a", "b", "c", "d", NULL})
}					t_cmd_token;

typedef struct s_lexer
{
	const char		*input;
	size_t			pos;
}					t_lexer;

t_cmd_token			*get_parsed_commands_line(char *line);
t_token				*_lexer(const char *input);
t_cmd_token			*_parse_commands(t_token *tokens);
void				free_cmds(t_cmd_token *cmds);
void				free_tokens(t_token *tokens);

#endif