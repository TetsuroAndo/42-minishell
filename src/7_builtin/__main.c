#include "ft_builtin.h"



#ifdef TEST_PWD
int main(int argc, char const **argv,char **env)
{
    t_info info;
    info.cwd = "/TEST/testdir";
    builtin_pwd(&info);
    return 0;
}
#endif // TEST_PWD

#ifdef TEST_CD
int main(int argc, char const **argv, char **env)
{
    t_info info;
    info.cwd = strdup("/TEST");
    builtin_pwd(&info);
    builtin_cd("/TEST/testdir", &info, NULL);
    builtin_pwd(&info);
    return 0;
}
#endif // TEST_CD