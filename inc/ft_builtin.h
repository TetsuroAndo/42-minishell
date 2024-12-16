#ifndef FT_BUILTIN_H
#define FT_BUILTIN_H

#include "system.h"
#include "ft_env.h"
#include <stdio.h>
#include <stdlib.h>


//wrapper関数の定義　関数ポインタ型の宣言





/**** funcs ****/
void builtin_pwd(const t_info *info);
void builtin_cd(char *absolute_path, t_info *info, t_list *env);
#endif