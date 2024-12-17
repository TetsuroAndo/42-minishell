#include "ft_builtin.h"
#include "ft_system.h"
#include <unistd.h>


int	main(int argc, char const **argv, char **env)
{
	t_info		*info;
	static char	*av[5] = {"echo", "abc", "def", NULL};
	static char	*av1[5] = {"cd", "test", NULL};

	// info.cwd = malloc(256);
	// getcwd(info.cwd,256);
	info = system_init();
	info->env_map = xlst_from_strs(env,info);
	xbuiltin("echo", av, info);
	xbuiltin("pwd", av, info);
	xbuiltin("cd", av1, info);
	xbuiltin("pwd", av, info);
	// test_cd(info);
	system_deinit(info);
	return (0);
}
