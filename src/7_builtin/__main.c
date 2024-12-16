#include "ft_builtin.h"
#include <unistd.h>



int test_cd(t_info *info)
{
    char *path;

    printf("pwd: ");
    builtin_pwd(info);
    path  = ".." ;
    printf("%s: ", path);
    builtin_cd(path, info, NULL);
    printf("相対パスは未対応\n\n");

    path  = "/TEST/testdir" ;
    printf("%s: ", path);
    builtin_cd(path, info, NULL);


    builtin_pwd(info);
    
    return 0;
}



int main(int argc, char const **argv, char **env)
{

    t_info info;
    info.cwd = malloc(256);
    getcwd(info.cwd,256);

    test_cd(&info);
    free(info.cwd);
    return 0;
}
