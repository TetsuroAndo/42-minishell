#include "ft_builtin.h"
#include "ft_env.h"
#include "ft_system.h"

t_status	builtin_export(const char *path, char **argv, t_info *info)
{
	printf("%s\n",env_get(info->env_map,"TESTTTT"));
	printf("%s\n",env_get(info->env_map,"PWD"));
	// env_export(info->env_map, argv[1]);
	return (E_NONE);
}
