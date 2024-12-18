#include "ft_env.h"
#include "ft_system.h"

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



t_status env_export(t_list **env, char *ent)
{
    char *key;
    key = ft_substr_l(ent,'=');
    if (!key)
        return E_ALLOCATE;
    // t_list *lst_ptr;
    // // lst_ptr = _get_ptr(env,key);
    // if (lst_ptr)//すでに存在する場合上書き
    // {
    //     lst_ptr->data = ent;//strdupするかしないか
    //     return E_NONE;
    // }
    // lst_ptr = ft_lstnew(ent);
    // if (!lst_ptr)
    //     return E_ALLOCATE;
    // lst_ptr->data = ent;
    // lst_ptr->next = NULL;
    // ft_lstadd_back(env, lst_ptr);
    return E_NONE;
}
