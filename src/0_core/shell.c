/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:45:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 16:40:41 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"
#include "minishell_info.h"

extern void	init_signals(void);

void		print_cmd_tokens(const t_cmd_token *cmds);

void	shell_loop(t_shell_info *info)
{
	char		*line;
	t_cmd_token	*cmds;

	(void)info;
	init_signals();
	while (1)
	{
		line = read_command_line(PROMPT);
		if (!line)
		{
			// EOF(Ctrl-D)などでNULLが返ってきた場合
			if (write(STDOUT_FILENO, "exit\n", 5) == -1)
				perror("write error");
			break ;
		}
		// get_parsed_commands_line()が入力読み取り→lexer→parseを行う
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
