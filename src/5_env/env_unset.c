#include "ft_env.h"
#include "ft_system.h"

//keyを削除
t_status env_unset(t_list *env, char *key)
{
    // //todo keyerror not a valid identifier
    // t_list *plst;
    // plst = _get_ptr(env, key);
    // if (!plst)
    //     return E_NONE;
    // //tdo linledListのheadを削除するとセグフォになりそう
    // env->next = lst_ptr->next;
    // ft_lstdelone(lst_ptr,free);
    return E_NONE;
}
