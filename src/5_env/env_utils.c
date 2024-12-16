#include "ft_env.h"
#include "system.h"

//keyから値を取得、なかったらNULL
char *env_get(t_list *env, char *key)
{
    return NULL;
}
//entityを追加


static t_status check_ent(char *ent)
{
    return E_NONE;
}
t_status env_export(t_list **env, char *ent)
{
    t_list *new;
    if (check_ent(ent))
      return 
    new = ft_lstnew(ent);
    if (!new)
        return NULL;
    ft_lstadd_back(env, new);
    

}
//keyを削除
t_status env_unset(t_list *env, char *key)
{

    return E_NONE;
}
//linkedlistからchar＊の配列へ
t_status env_update(t_list *env_map, char **envp)
{

    return E_NONE;
}
