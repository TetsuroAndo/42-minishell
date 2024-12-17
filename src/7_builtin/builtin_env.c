/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:47:05 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 22:39:27 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "ft_env.h"
#include "ft_system.h"

t_status	builtin_env(const char *path, char **argv, t_info *info)
{
	char	**envp;

	envp = ft_list_to_strs(info->env_map);
	if (!envp)
		return (E_ALLOCATE);
	// 引数がわたされるため、Argvを使用する必要あり
	(void)path;
	(void)argv;
	ft_putstrs_fd(envp, "\n", STDOUT_FILENO);
	return (E_NONE);
}
