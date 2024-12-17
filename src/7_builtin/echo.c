/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:48:32 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 16:41:19 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "ft_env.h"
#include "system.h"

t_status	builtin_echo(const char *path, char **argv, t_info *info)
{
	int	i;
	int	is_option_n;

	(void)path;
	// todo　echoが失敗する場合を調べる
	// argv[0]="echo", argv[1]="arg1", argv[2]="arg2", ...
	// 基本的には改行付きで残りを出力。-nオプションなどは後で実装可能。
	i = 1;
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	printf("\n");
	return (E_NONE);
}
