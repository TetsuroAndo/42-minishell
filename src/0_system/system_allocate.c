/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_allocate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:27:29 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 21:27:38 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_system.h"

void	*xmalloc(size_t size, t_info *info)
{
	char	*memory;

	memory = malloc(size);
	if (!memory)
	{
		system_exit(info, E_ALLOCATE);
	}
	return ((void *)memory);
}
