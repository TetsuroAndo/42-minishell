#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# include "ft_env.h"
# include "ft_system.h"
# include <stdio.h>
# include <stdlib.h>

// wrapper関数の定義　関数ポインタ型の宣言
typedef t_status	(*builtin_func_t)(const char *path, char **argv,
		t_info *info);

// static char **builtin_path = {"echo","cd","pwd","export","unset","env","exit"};
/**** funcs ****/
t_status			builtin_pwd(const char *path, char **argv, t_info *info);
t_status			builtin_cd(const char *path, char **argv, t_info *info);
t_status			builtin_echo(const char *path, char **argv, t_info *info);
t_status			builtin_export(const char *path, char **argv, t_info *info);
t_status			builtin_unset(const char *path, char **argv, t_info *info);
t_status			builtin_exit(const char *path, char **argv, t_info *info);
t_status			builtin_env(const char *path, char **argv, t_info *info);
#endif