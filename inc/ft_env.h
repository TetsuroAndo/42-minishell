/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:48:09 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/18 21:48:11 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

# include "libft_h"

/**** funcs ****/

// keyから値を取得、なかったらNULL
char		*env_get(t_list *env, char *key);
// entityを追加
t_status	env_export(t_list *env, char *ent);
// keyを削除
t_status	env_unset(t_list *env, char *key);

/**** utils ****/
int			_check_key(char *key);
int			__cmp(void *data, void *key);

#endif