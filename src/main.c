/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:45:19 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 00:02:17 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

extern void init_signals(void);

void print_cmd_tokens(const t_cmd_token *cmds);

void shell_loop(t_info *info)
{
	char *line;
	t_cmd_token *cmds;

	(void)info;
	init_signals();
	while (1)
	{
		line = read_command_line(PROMPT);
		if (!line)
		{
			ft_dprintf(STDOUT_FILENO, "exit\n");
			break;
		}
		cmds = lexer(line);
		free(line);
		if (!cmds)
			continue;
		print_cmd_tokens(cmds);
		free_cmds(cmds);
	}
}

int main(int argc, char **argv, char **envp)
{
	t_info info;

	(void)argc;
	(void)argv;
	(void)envp;
	// シェル情報構造体を初期化
	// info.cwd = getcwd(NULL, 0); // カレントディレクトリの取得
	// info.envp = envp;           // とりあえず既存envpをそのまま使う
	// info.last_status = 0;
	// メインループ開始
	shell_loop(&info);
	free(info.cwd);
	return (0);
}
