/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:41:18 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 10:56:23 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_info.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef PROMPT
#  define PROMPT "minishell> "
# endif

typedef struct s_shell_info
{
	char *cwd;       // 現在の作業ディレクトリ
	char **envp;     // 環境変数配列（必要に応じて別の管理方法でも可）
	int last_status; // 前回実行コマンドの終了ステータス
						// 他にも必要に応じて構造を拡張
}		t_shell_info;

/* <----------- 0_core -----------> */
int		is_builtin(char *cmd);
int		exec_builtin(void);
char	*read_command_line(const char *prompt);
void	shell_loop(t_shell_info *info);

/* <----------- 6_signals -----------> */
void	init_signals(void);

/* <----------- 7_builtin -----------> */
void	builtin_pwd(const t_info *info);

#endif