/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:48:52 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/20 05:21:22 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

t_status	env_export(t_list *env, char *ent)
{
	char	key[PATH_MAX];
	char	*ent_cpy;
	int		deli;
	t_list	*lst;

	ent_cpy = ft_strdup(ent);
	if (!ent_cpy)
		return (E_ALLOCATE);
	if (_check_key(key))
		return (free(ent_cpy), E_ENV_KEY);
	deli = ft_strspn(ent, "=");
	ft_strncpy(key, ent, deli);
	lst = ft_list_find(env, key, __cmp);
	if (lst) //すでに存在する場合上書き
	{
		free(lst->data);
		lst->data = ent_cpy;
		return (E_NONE);
	}
	lst = ft_lstnew(ent_cpy);
	if (!lst)
		return (free(ent_cpy), E_ALLOCATE);
	ft_lstadd_back(&env, lst);
	return (E_NONE);
}
