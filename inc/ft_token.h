/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:20:59 by teando            #+#    #+#             */
/*   Updated: 2024/12/19 02:08:10 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_status
{
	E_NONE = 0, //正常
	E_ALLOCATE = 1,
	E_ENV_KEY = 1,
	E_SYNTAX = 1,
	E_PIPE = 1,
	E_COMMAND_NOT_FOUND = 127,
	E_SIGINT = 130,
	E_SIGQUIT = 131,
}						t_status;

typedef enum e_token_type
{
	TT_CMD,          // コマンドトークン
	TT_PIPE,         // パイプ
	TT_REDIRECT_IN,  // 入力リダイレクト
	TT_REDIRECT_OUT, // 出力リダイレクト
	TT_APPEND,       // 追記リダイレクト
	TT_HEREDOC,      // ヒアドキュメント
	TT_AND_AND,      // &&
	TT_OR_OR,        // ||
	TT_LPAREN,       // (
	TT_RPAREN,       // )
	TT_EOF,          // 終端
	TT_ERROR         // エラー
}						t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
}						t_token;

typedef struct s_cmd_token
{
	t_token_type type; // CMD or PIPEなど
	char *path;        // 実行するコマンド(e.g. "echo")
	char **args;       // 引数列(e.g. {"echo", "a", "b", "c", "d", NULL})
}						t_cmd_token;

typedef struct s_redirect
{
	t_token_type		type;
	char				*filename;
	struct s_redirect	*next;
}						t_redirect;

typedef struct s_command
{
	char *name;            // コマンド名 (例: "echo")
	char **args;           // 引数リスト (例: ["echo","hello","world",NULL])
	t_redirect *redirects; // リダイレクト一覧
}						t_command;

typedef struct s_pipeline
{
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}						t_pipeline;

typedef struct s_ast_node
{
	t_token_type		type;
	union
	{
		t_command		command;
		t_pipeline		pipeline;
	} u_data;
}						t_ast_node;

// typedef struct s_ast_node
// {
// 	t_token_type		type;
// 	// int                    file_type;
// 	char				**args;
// 	struct s_ast_node	*left;
// 	struct s_ast_node	*right;
// }						t_ast_node;

#endif