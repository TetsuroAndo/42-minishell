/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:27:54 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 23:05:08 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_system.h"

void	system_exit(t_info *info, t_status status)
{
	system_deinit(info);
	exit(status);
}

