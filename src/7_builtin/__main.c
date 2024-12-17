#include "ft_builtin.h"
#include "ft_system.h"
#include <unistd.h>

int	test_cd(t_info *info)
{
	char	*path;

	printf("pwd: ");
	builtin_pwd(path, NULL, NULL);
	path = "..";
	printf("%s: ", path);
	builtin_cd(path, NULL, info);
	printf("相対パスは未対応\n\n");
	path = "/TEST/testdir";
	printf("%s: ", path);
	builtin_cd(path, NULL, info);
	builtin_pwd(path, NULL, NULL);
	return (0);
}

int	main(int argc, char const **argv, char **env)
{
	t_info		*info;
	static char	*av[5] = {"echo", "abc", "def", NULL};

	// info.cwd = malloc(256);
	// getcwd(info.cwd,256);
	info = system_init(env);
	xbuiltin("echo", av, info);
	// test_cd(info);
	system_deinit(info);
	return (0);
}
