#include "system.h"
t_info *system_init();
{
    t_info *info = malloc(sizeof(t_info));
    if (!info)
        reuturn NULL;
    info->ast = NULL;
    info->env_map = ft_lstnew;
    info->envp = environ;
    info->is_env_updated = 0;
    info->cwd = malloc(sizeof(char) * MAX_WORD_LEN);
    getcwd(info->cwd);
    if(!info->ast || !info->env_map || !info->cwd)
        return NULL;
    return info;
}


void system_deinit(t_info *info)
{
    if (!info)
        return;
    ft_lstclear(&info->env_map, free);
    //ast_clear(info->ast);
    free(info->cwd);
    free(info);
}
