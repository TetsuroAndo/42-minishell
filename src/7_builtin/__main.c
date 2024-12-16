#include "ft_builtin.h"



#ifdef TEST_PWD
int main(int argc, char const **argv,char **env)
{
    t_info info;
    info.cwd = "/TEST/testdir";
    builtint_pwd(&info);
    return 0;
}
#endif // TEST_PWD
