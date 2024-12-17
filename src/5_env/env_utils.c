#include "ft_env.h"
#include "ft_system.h"



static t_list *_get_ptr(const t_list *env, const char *key)
{
    
}

static char *_get_key(char *ent)
{
    static char key[MAX_WORD_LEN];
    int index = 0;
    //char *delimiter = ft_strchr(ent, '=');
    while(ent[index] && ent[index] != '=')
    {
        key[index] = ent[index];
    }
    


    return key;
}
/*
*keyの有効性を確かめる
*/
static int _check_key(char *key)
{
    /*
    アルファベット（a-z, A-Z）またはアンダースコア（_）で始まる必要がある。
    2文字目以降は、アルファベット、数字（0-9）、またはアンダースコアが使える。
    空白や特殊記号（例: !, @, #, - など）は使用できない(chatGPT)
    */
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
    lst_ptr->next = NULL;
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
    //tdo linledListのheadを削除するとセグフォになりそう
    env->next = lst_ptr->next;
    ft_lstdelone(lst_ptr,free);
    return E_NONE;
}

//linkedlistからchar＊の配列へ
t_status env_update(t_list *env_map, char **envp)
{

    return E_NONE;
}
