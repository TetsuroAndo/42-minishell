#include "ft_builtin.h"
#include "ft_env.h"
#include "system.h"

/*
*ref char * getcwd(char *buf, size_t size);
返り値はpwdを返すべきか、エラーを返すべきか（グローバル変数でエラーを変更できる？）
*/
void	builtin_pwd(const char *path, char **argv, t_info *info)
{
	(void)path;
	(void)argv;
	// char cwd[MAX_WORD_LEN];
	if (info->cwd == NULL)
	{
		// todo errorハンドリング
		return ;
	}
	printf("%s\n", info->cwd);
}
