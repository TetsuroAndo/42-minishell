#include "ft_system.h"

t_info	*system_init(char **envp)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->ast = NULL;
	info->env_map = NULL; // ft_lstnew;
	info->envp = NULL;
	info->is_env_updated = 1;
	// info->cwd = malloc(sizeof(char) * MAX_WORD_LEN);
	getcwd(info->cwd, MAX_WORD_LEN);
	// if(!info->ast || !info->env_map || !info->cwd)
	//     return (NULL);
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
