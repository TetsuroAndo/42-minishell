#ifndef FT_BUILTIN_H
#define FT_BUILTIN_H

#include "system.h"
#include "ft_env.h"
#include <stdio.h>
#include <stdlib.h>


//wrapper関数の定義　関数ポインタ型の宣言





/**** funcs ****/
t_status builtin_pwd(const t_info *info);
t_status builtin_cd(char *absolute_path, t_info *info, t_list *env);
t_status	exec_echo(const char *path, char **argv, t_info *info);
t_status builtin_export(const char *path, char **argv, t_info *info);
t_status builtin_unset(const char *path, char **argv, t_info *info);
void	exec_exit(const char *path, char **argv, t_info *info);
int	exec_env(const char *path, char **argv, t_info *info);
#endif