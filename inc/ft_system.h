/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:53:59 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 17:33:41 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H
# include "libft.h"
# include <stdio.h>

# define MAX_WORD_LEN 2048
// minishell.hと分けなくても良いかもしれないけど
//他のdirでこっちinfo.hはincludeできるけだminishell.hはinclude禁止にするとテストが捗りそう

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

typedef struct s_ast_node
{
	t_token_type		type;
	// int                    file_type;
	char				**args;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}						t_ast_node;

typedef struct s_info
{
	t_ast_node *ast;    // root
	t_list *env_map;    //線形リストのhead
	char **envp;        // envpのポインタ配列
	int is_env_updated; // envpが最新のものかどうか
	char				cwd[MAX_WORD_LEN];
	t_status status; //グローバル変数として持てなかったら

	/* optional info */
}						t_info;

t_info					*system_init(char **env);
void					system_deinit(t_info *info);

#endif
