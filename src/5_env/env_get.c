/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:48:44 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/18 19:52:59 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "ft_system.h"

// keyから値を取得、なかったらNULL

int	__cmp(void *data, void *key)
{
	return (ft_strncmp((char *)data, (char *)key, ft_strlen((char *)key)));
}

char	*env_get(t_list *env, char *key)
{
	char	uniq_key[MAX_PATH];
	t_list	*lst;
	char	*unique_key;

	// printf("%s\n",__func__);
	ft_strlcpy(uniq_key, key, MAX_PATH);
	ft_strlcat(uniq_key, "=", MAX_PATH);
	lst = ft_list_find(env, uniq_key, __cmp);
	unique_key = malloc(ft_strlen(key) + 2);
	lst = ft_list_find(env, key, __cmp);
	// note leak!!!MAX_PATHとして持っても良い
	if (!lst)
		return (ft_strdup(""));
	return (ft_substr_r(lst->data, '='));
}
