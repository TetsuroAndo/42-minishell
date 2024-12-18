/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:45:19 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 18:18:41 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern void	init_signals(void);

void	shell_loop(t_info *info)
{
	char	*line;

	init_signals();
	while (1)
	{
		line = read_command_line(PROMPT);
		if (!line)
		{
			ft_dprintf(STDOUT_FILENO, "exit\n");
			break ;
		}
		// info->source_lineに格納してからxlexer呼び出し
		info->source_line = line;
		if (xlexer(info) == E_NONE)
		{
			// xlexer終了後、info->token_listにt_cmd_tokenリストがある
			print_cmd_tokens(info->token_list);
			ft_lstclear(&info->token_list, free_cmd_token);
		}
		free(line);
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
	shell_loop(&info);
	return (0);
}
