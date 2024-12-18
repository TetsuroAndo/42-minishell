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

#include "minishell.h"

int	exec_exit(char **argv)
{
	(void)argv; // 引数未対応だが将来対応可能
	printf("exit\n");
	exit(0);
	return (0); // 実行されない
}
