#include "ft_env.h"
#include "system.h"
#include "ft_builtin.h"

static int check_valid_dir(char *absolute_path)
{
    //todo
    return 0;
}

t_status builtin_cd(char *path, char **argv, t_info *info)
{
    //todo path -> absolute pathはこの関数の中で行う方が良いか

    //char cwd[MAX_WORD_LEN];
    (void)argv;
    if (check_valid_dir(path))
    {
        //todo errorハンドリング
        return;
    }

    //todo 環境変数PWDを更新する
    //btmap_export(env,"PWD", absolute_path);
    //optional OLDPWDを更新する
    //btmap_export(env,"OLDPWD", info->cwd);
    free(info->cwd);
    info->cwd = ft_strdup(path);
}
