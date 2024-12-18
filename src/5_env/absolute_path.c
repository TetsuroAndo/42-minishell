/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:06:10 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/18 22:10:04 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "ft_system.h"

t_status	xabsolute_path(char *dstpath, char *srcpath, t_list *env_map,
		int mode)
{
	char	*envpathes;

	envpathes = env_get(env_map, "PATH");
	ft_strlcpy(dstpath, envpathes, MAX_PATH);
	ft_strlcat(dstpath, "/", MAX_PATH);
	ft_strlcat(dstpath, srcpath, MAX_PATH);
	return (E_NONE);
}
