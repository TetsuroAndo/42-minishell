#include "ft_env.h"
#include "minishell_info.h"
#include "ft_builtin.h"
/*
*ref char * getcwd(char *buf, size_t size);
返り値はpwdを返すべきか、エラーを返すべきか（グローバル変数でエラーを変更できる？）
*/
void builtin_pwd(const t_info *info)
{
    //char cwd[MAX_WORD_LEN];
    if (info->cwd == NULL)
    {
        //todo errorハンドリング
        return;
    }
    printf("%s\n", info->cwd);
}

