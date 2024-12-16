#include "ft_env.h"
#include "minishell_info.h"

static int check_valid_dir(char *absolute_path)
{
    //todo
    return 0;
}

void builtint_cd(char *absolute_path, t_info *info, t_btmap *env)
{
    //char cwd[MAX_WORD_LEN];
    if (check_valid_dir(absolute_path))
    {
        //todo errorハンドリング
        return;
    }

    //todo 環境変数PWDを更新する
    //btmap_export(env,"PWD", absolute_path);
    //optional OLDPWDを更新する
    //btmap_export(env,"OLDPWD", info->cwd);
    info->cwd = ft_strdup(absolute_path);
}
