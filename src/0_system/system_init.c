#include "ft_system.h"

t_info	*system_init()
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->source_line = NULL;
	info->token_list = NULL;
	info->ast = NULL;
	info->env_map = NULL;//ft_list_from_strs(envp);
	// ft_bzero(info->files, MAX_FD * sizeof(int));
	info->status = E_NONE;
	getcwd(info->cwd, MAX_PATH);
	// if (!info->ast || !info->env_map)
	// 	exit(E_ALLOCATE);
	return (info);
}

void	system_deinit(t_info *info)
{
	if (!info)
		return ;
	free(info->source_line);
	ft_lstclear(&info->token_list,free);
	ft_lstclear(&info->env_map, free);
	// ast_clear(info->ast);
	free(info);
}
