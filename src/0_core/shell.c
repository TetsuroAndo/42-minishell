/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:45:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 15:09:08 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "lexer.h"
#include "minishell.h"
#include "lexer.h"
#include "minishell_info.h"

extern void init_signals(void);

// 元のfree_cmds関数
static void free_cmds(t_cmd_token *cmds)
{
	if (!cmds)
		return;
	for (int i = 0; cmds[i].type != TT_EOF && cmds[i].type != TT_ERROR; i++)
	{
		free(cmds[i].path);
		if (cmds[i].args)
		{
			for (int j = 0; cmds[i].args[j]; j++)
				free(cmds[i].args[j]);
			free(cmds[i].args);
		}
	}
	free(cmds);
}

// 元のprint_cmd_tokens関数
static void print_cmd_tokens(const t_cmd_token *cmds)
{
	int i, j;

	printf("token modified_line[...]:\n");
	for (i = 0; cmds[i].type != TT_EOF && cmds[i].type != TT_ERROR; i++)
	{
		printf("token%d = {", i + 1);
		if (cmds[i].type == TT_CMD)
		{
			printf("CMD, \"%s\", \"", cmds[i].path ? cmds[i].path : "");
			if (cmds[i].args)
			{
				for (j = 0; cmds[i].args[j] != NULL; j++)
				{
					printf("%s", cmds[i].args[j]);
					if (cmds[i].args[j + 1] != NULL)
						printf(" ");
				}
			}
			printf("\"}\n");
		}
		else if (cmds[i].type == TT_PIPE)
			printf("PIPE, NULL, NULL}\n");
		else
			printf("OTHER, NULL, NULL}\n");
	}
}

void shell_loop(t_shell_info *info)
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
			// EOF(Ctrl-D)などでNULLが返ってきた場合
			if (write(STDOUT_FILENO, "exit\n", 5) == -1)
				perror("write error");
			break;
		}
		// get_parsed_commands_line()が入力読み取り→lexer→parseを行う
		cmds = get_parsed_commands_line(line);
		if (!cmds)
		{
			free(line);
			continue;
		}
		print_cmd_tokens(cmds);
		free_cmds(cmds);
		free(line);
	}
}
