#include "ft_env.h"
#include "system.h"



static t_list *_get_ptr(t_list *env, char *key)
{
    
}

static char *_get_key(char *ent)
{
    char *key;
    return ;
}

static int _check_key(char *key)
{
    //todo TEST=など
    return 0;
}

//keyから値を取得、なかったらNULL
char *env_get(t_list *env, char *key)
{
    return NULL;
}

t_status env_export(t_list **env, char *ent)
{
    char *key;
    key = _get_key(ent);
    if (!key)
        return E_ENV_KEY;
    t_list *lst_ptr;
    lst_ptr = _get_ptr(env,key);
    if (lst_ptr)//すでに存在する場合上書き
    {
        lst_ptr->content = ent;//strdupするかしないか
        return E_NONE;
    }
    lst_ptr = ft_lstnew(ent);
    if (!lst_ptr)
        return E_ALLOCATE;
    lst_ptr->content = ent;
    ft_lstadd_back(env, lst_ptr);
    return E_NONE;
}

//keyを削除
t_status env_unset(t_list *env, char *key)
{
    //todo keyerror not a valid identifier
    if (_check_key)
        return E_ENV_KEY;
    t_list *lst_ptr;
    lst_ptr = _get_ptr(env, key);
    if (!lst_ptr)
        return E_NONE;//keyが見つからない場合は正常終了
    while(env->next!=NULL && env->next!=lst_ptr)
    {
        env = env->next;
    }
    env->next = lst_ptr->next;
    ft_lstdelone(lst_ptr,free);
    return E_NONE;
}

//linkedlistからchar＊の配列へ
t_status env_update(t_list *env_map, char **envp)
{

    return E_NONE;
}
