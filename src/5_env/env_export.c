/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:48:52 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/18 20:44:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "ft_system.h"

t_status	env_export(t_list *env, char *ent)
{
	char	uniq_key[MAX_PATH];
	char	*ent_cpy;
	int		deli;
	t_list	*lst;

	ent_cpy = ft_strdup(ent);
	if (_check_key(uniq_key))
		return (E_ENV_KEY);
	if (!ent_cpy)
		return (E_ALLOCATE);
	deli = ft_strspn(ent, "=");
	ft_strncpy(uniq_key, ent, deli + 1);
	lst = ft_list_find(env, uniq_key, __cmp);
	if (lst) //すでに存在する場合上書き
	{
		printf("key already exist%s\n", lst->data);
		free(lst->data);
		lst->data = ent_cpy;
		return (E_NONE);
	}
	printf("key dosent exist %s\n", ent_cpy);
	lst = ft_lstnew(ent_cpy);
	if (!lst)
		return (free(ent_cpy), E_ALLOCATE);
	ft_lstadd_back(&env, lst);
	return (E_NONE);
}
