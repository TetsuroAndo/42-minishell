#include "ft_system.h"

t_info	*system_init(char **envp)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->ast = NULL;
	info->env_map = ft_list_from_strs(envp);
	// ft_bzero(info->files, MAX_FD * sizeof(int));
	info->status = E_NONE;
	getcwd(info->cwd, MAX_PATH);
	if (!info->ast || !info->env_map)
		exit(NULL);
	return (info);
}

void	system_deinit(t_info *info)
{
	if (!info)
		return ;
	ft_lstclear(&info->env_map, free);
	// ast_clear(info->ast);
	free(info->cwd);
	free(info);
}
