#include "ft_builtin.h"
#include "ft_env.h"
#include "ft_system.h"
#include <unistd.h>

int	main(int argc, char const **argv, char **env)
{
	t_info		*info;
	static char	*av[5] = {"echo", "abc", "def", NULL};
	static char	*av1[5] = {"cd", "SAMPLE_KEY", NULL};
	static char	*av4[5] = {"unset", "SAMPLE_KEY2", NULL};
	static char	*av2[5] = {"export", "SAMPLE_KEY=AIOUE", NULL};
	static char	*av3[5] = {"export", "SAMPLE_KEY2=TSET", NULL};

	// info.cwd = malloc(256);
	// getcwd(info.cwd,256);
	info = system_init();
	info->env_map = xlst_from_strs(env, info);
	// xbuiltin("echo", av, info);
	// printf("SAMPLE_KEY %s\n", env_get(info->env_map, "SAMPLE_KEY"));
	// printf("SAMPLE_KEY2 %s\n", env_get(info->env_map, "SAMPLE_KEY2"));
	// xbuiltin("export", av2, info);
	// printf("SAMPLE_KEY %s\n", env_get(info->env_map, "SAMPLE_KEY"));
	// xbuiltin("export", av2, info);
	// xbuiltin("export", av3, info);
	// // xbuiltin("env", NULL, info);
	// xbuiltin("unset", av1, info);
	// // xbuiltin("unset", av4, info);
	// printf("SAMPLE_KEY %s\n", env_get(info->env_map, "SAMPLE_KEY"));
	// printf("SAMPLE_KEY2 %s\n", env_get(info->env_map, "SAMPLE_KEY2"));
	xbuiltin("pwd", av, info);
	xbuiltin("cd", av1, info);
	xbuiltin("pwd", av, info);
	// xbuiltin("env", av, info);
	xbuiltin("exit", NULL, info);
	system_deinit(info);
	return (0);
}
