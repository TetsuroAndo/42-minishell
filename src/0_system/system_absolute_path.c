#include "ft_system.h"
t_status xabsolute_path(char *dstpath, char *srcpath, char *envpathes, int mode)
{
    ft_strlcpy(dstpath,envpathes,MAX_PATH);
    ft_strlcat(dstpath,"/",MAX_PATH);
    ft_strlcat(dstpath,srcpath,MAX_PATH);
    return E_NONE;
}