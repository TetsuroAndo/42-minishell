/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:38:28 by teando            #+#    #+#             */
/*   Updated: 2024/12/16 17:52:26 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static char **builtin_path = {"echo","cd","pwd","export","unset","env","exit"};

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "pwd"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	if (!ft_strcmp(cmd, "env"))
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

// int	exec_builtin(void)
// {
// 	if (!ft_strcmp(argv[0], "echo"))
// 		return ();
// 	if (!ft_strcmp(argv[0], "cd"))
// 		return ();
// 	if (!ft_strcmp(argv[0], "pwd"))
// 		return (builtin_pwd());
// 	if (!ft_strcmp(argv[0], "export"))
// 		return ();
// 	if (!ft_strcmp(argv[0], "unset"))
// 		return ();
// 	if (!ft_strcmp(argv[0], "env"))
// 		return ();
// 	if (!ft_strcmp(argv[0], "exit"))
// 		return ();
// 	return (127);
// }
