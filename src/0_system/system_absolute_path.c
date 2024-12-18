#include "ft_env.h"
#include "ft_system.h"

t_status	xabsolute_path(char *dstpath, char *srcpath, int mode)
{
	envpathes = env_get("PATH");
	ft_strlcpy(dstpath, envpathes, MAX_PATH);
	ft_strlcat(dstpath, "/", MAX_PATH);
	ft_strlcat(dstpath, srcpath, MAX_PATH);
	return (E_NONE);
}
