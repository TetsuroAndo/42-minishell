/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:47:05 by teando            #+#    #+#             */
/*   Updated: 2024/12/16 18:04:35 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_env(char **argv, char **envp)
{
	size_t	i;

	i = 0;
	(void)argv;
	while (envp[i])
		printf("%s\n", envp[i++]);
	return (0);
}
