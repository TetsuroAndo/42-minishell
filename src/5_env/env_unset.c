#include "ft_env.h"
#include "ft_system.h"




// void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *),
// 		void (*free_fct)(void *))
// {
// 	t_list	*current;
// 	t_list	*prev;
// 	t_list	*tmp;

// 	current = *begin_list;
// 	prev = 0;
// 	while (current)
// 	{
// 		if ((*cmp)(current->data, data_ref) == 0)
// 		{
// 			tmp = current->next;
// 			(*free_fct)(current->data);
// 			free(current);
// 			if (!prev)
// 				*begin_list = tmp;
// 			else
// 				prev->next = tmp;
// 			current = tmp;
// 		}
// 		else
// 		{
// 			prev = current;
// 			current = current->next;
// 		}
// 	}
// }

int __cmp(void *data, void *key)
{
	return ft_strncmp((char *)data, (char *)key, ft_strlen((char *)key));
}
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
