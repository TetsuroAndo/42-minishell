#include "ft_env.h"

//keyから値を取得、なかったらNULL
char *env_get(t_list *env, char *key);
//entityを追加
char *env_export(t_list **env, char *ent)
{
    t_list *new = ft_lstnew(ent);
    if (!new)
        return NULL;
    ft_lstadd_back(env, new);
    

}
//keyを削除
char *env_unset(t_list *env, char *key);


