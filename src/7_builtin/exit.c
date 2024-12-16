/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:45:58 by teando            #+#    #+#             */
/*   Updated: 2024/12/16 18:04:37 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "ft_env.h"
#include "system.h"

void	exec_exit(const char *path, char **argv, t_info *info)
{
	(void)argv; // 引数未対応だが将来対応可能
	printf("exit\n");//debug ??
	system_deinit(info);
	exit(info->status);
}
