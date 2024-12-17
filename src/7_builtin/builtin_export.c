#include "ft_builtin.h"
#include "ft_env.h"
#include "ft_system.h"

t_status builtin_export(const char *path, char **argv, t_info *info)
{
    info->is_env_updated = 1;
    env_export(info->env_map,argv[1]);
    return E_NONE;
}