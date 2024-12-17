/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:47:05 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 16:54:48 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "ft_env.h"
#include "ft_system.h"

t_status	builtin_env(const char *path, char **argv, t_info *info)
{
	size_t	i;

	(void)path;
	if (info->is_env_updated)
	{
		env_update(info->env_map, info->envp);
		info->is_env_updated = 0;
	}
	i = 0;
	(void)argv;
	while (info->envp[i])
		printf("%s\n", info->envp[i++]);
	return (E_NONE);
}
