#include "ft_env.h"

/*
*ref char * getcwd(char *buf, size_t size);
返り値はpwdを返すべきか、エラーを返すべきか（グローバル変数でエラーを変更できる？）
*/
void builtint_pwd(t_btmap *env)
{
    //char cwd[MAX_WORD_LEN];
    char *cwd;
    cwd = tmap_get(env,"PWD");
    printf("%d\n", cwd);
}