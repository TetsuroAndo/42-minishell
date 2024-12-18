#include "ft_env.h"
#include "ft_system.h"
//keyから値を取得、なかったらNULL

int __cmp(void *data, void *key)
{
	return ft_strncmp((char *)data, (char *)key, ft_strlen((char *)key));
}

char *env_get(t_list *env, char *key)
{
    //printf("%s\n",__func__);
    char *unique_key = ft_strndup(key, ft_strlen((char *)key));
    t_list *lst = ft_list_find(env,key,__cmp);
    if (!lst)
        return ft_strdup("");
    return ft_substr_r(lst->data,'=');
}