#ifndef FT_ENV_H
# define FT_ENV_H

# include "ft_system.h"

/**** funcs ****/

// keyから値を取得、なかったらNULL
char		*env_get(t_list *env, char *key);
// entityを追加
t_status	env_export(t_list **env, char *ent);
// keyを削除
t_status	env_unset(t_list *env, char *key);

/**** utils ****/
int			_check_key(char *key);
int			__cmp(void *data, void *key);

#endif