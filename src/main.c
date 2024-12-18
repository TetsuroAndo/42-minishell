/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:45:19 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 22:30:50 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern void	init_signals(void);

void	shell_loop(t_info *info)
{
	while (1)
	{
		info->source_line = read_line_until_balanced(PROMPT);
		if (!info->source_line)
		{
			ft_dprintf(STDOUT_FILENO, "exit\n");
			break ;
		}
		if (xlexer(info) == E_NONE)
		{
			print_cmd_tokens(info->token_list);
			ft_lstclear(&info->token_list, free_cmd_token);
		}
		free(info->source_line);
		info->source_line = NULL;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	(void)argc;
	(void)argv;
	(void)envp;
	ft_memset(&info, 0, sizeof(t_info));
	init_signals();
	shell_loop(&info);
	return (0);
}
