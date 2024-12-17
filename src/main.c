/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:45:19 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 17:35:49 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

extern void	init_signals(void);

void		print_cmd_tokens(const t_cmd_token *cmds);

void	shell_loop(t_info *info)
{
	char		*line;
	t_cmd_token	*cmds;

	(void)info;
	init_signals();
	while (1)
	{
		line = readline(PROMPT);
		if (line && *line)
			add_history(line);
		if (!line)
		{
			ft_dprintf(STDOUT_FILENO, "exit\n");
			break ;
		}
		cmds = get_parsed_commands_line(line);
		if (!cmds)
		{
			free(line);
			continue ;
		}
		print_cmd_tokens(cmds);
		free_cmds(cmds);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

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
