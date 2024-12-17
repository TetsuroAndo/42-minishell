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

void print_tokens(const t_token *tokens);

void shell_loop(t_info *info)
{
	char *line;
	t_token *tokens;

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
		tokens = lexer(line);
		free(line);
		if (!tokens)
			continue;
		print_tokens(tokens);
		free_tokens(tokens);
	}
}

int main(int argc, char **argv, char **envp)
{
	t_info info;

	(void)argc;
	(void)argv;
	(void)envp;
	ft_memset(&info, 0, sizeof(t_info));
	shell_loop(&info);
	return (0);
}
