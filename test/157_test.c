#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_info *info = system_init();
	if (argc == 1)
		info->source_line = "echo a b c | env";
	else
		info->source_line = argv[1];
	info->env_map = ft_list_from_strs(env);
	xlexer(info);

	t_list *head = info->token_list;
	while (head)
	{
		xbuiltin(head->data->path, head->data->args, env);
		head = head->next;
	}

	system_exit(info, 0);
}