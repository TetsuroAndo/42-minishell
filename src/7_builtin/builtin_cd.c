#include "ft_builtin.h"
#include "ft_env.h"
#include "ft_system.h"
#include <unistd.h>
#include <stdio.h>
// #include <sys/types.h>
#include <errno.h>
#include <string.h>


// static int	check_valid_dir(const char *absolute_path)
// {
// 	// todo
// 	//stat()
// 	return (0);
// }

t_status	builtin_cd(const char *path, char **argv, t_info *info)
{
	// todo path -> absolute pathはこの関数の中で行う方が良いか
	// char cwd[MAX_WORD_LEN];
	(void)argv;
	t_status status;
	char absolute_path[MAX_PATH];
	if (argv[1] == NULL)
	{
        // 余裕があればROOTに移動
        return (E_NONE);
    }
	status = xabsolute_path(absolute_path, argv[1], "/path1:path2", F_OK);
	status = chdir(absolute_path);
	// printf("absolute_path: %s\n", absolute_path);
	printf("cd: %s: %s\n", argv[1], strerror(errno));
	// if (check_valid_dir(argv[1]))
	// {
	// 	// todo errorハンドリング
	// 	return (E_NONE);
	// }
	// todo 環境変数PWDを更新する
	// btmap_export(env,"PWD", absolute_path);
	// optional OLDPWDを更新する
	// btmap_export(env,"OLDPWD", info->cwd);
	if (!status)
		ft_strlcpy(info->cwd, absolute_path, MAX_PATH);
	return (E_NONE);
}
