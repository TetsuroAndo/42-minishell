#ifndef FT_ENV_H
# define FT_ENV_H

# include "libft.h"
# include "system.h"
# include <stdlib.h>

/**** funcs ****/

t_status	env_update(t_list *env_map, char **envp);
// keyから値を取得、なかったらNULL
char		*env_get(t_list *env, char *key);
// entityを追加
t_status	env_export(t_list **env, char *ent);
// keyを削除
t_status	env_unset(t_list *env, char *key);
#endif