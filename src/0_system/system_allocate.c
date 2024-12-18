/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_allocate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:27:29 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 16:48:32 by teando           ###   ########.fr       */
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

t_list	*xlstnew(char *data, t_info *info)
{
	t_list	*list;

	list = ft_lstnew((void *)data);
	if (!list)
		system_exit(info, E_ALLOCATE);
	return (list);
}

t_list	*xlst_from_strs(char **strs, t_info *info)
{
	t_list	*list;

	list = ft_list_from_strs(strs);
	if (!list)
		system_exit(info, E_ALLOCATE);
	return (list);
}

char	**xlst_to_strs(t_list *lst, t_info *info)
{
	char	**strs;

	strs = ft_list_to_strs(lst);
	if (!strs)
		system_exit(info, E_ALLOCATE);
	return (strs);
}
