#include "ft_env.h"
#include "ft_system.h"
//keyから値を取得、なかったらNULL

int __cmp(void *data, void *key)
{
	return ft_strncmp((char *)data, (char *)key, ft_strlen((char *)key));
}

char *env_get(t_list *env, char *key)
{
    printf("%s\n",__func__);
    t_list *lst = ft_list_find(env,key,__cmp);
    if (!lst)
        return NULL;
    return lst->data;
}