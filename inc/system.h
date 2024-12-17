#ifndef SYSTEM_H
#define SYSTEM_H
#include "ft_ast.h"
#include "libft.h"

#define MAX_WORD_LEN 2048
//minishell.hと分けなくても良いかもしれないけど
//他のdirでこっちinfo.hはincludeできるけだminishell.hはinclude禁止にするとテストが捗りそう

typedef enum e_status
{
    E_NONE=0,//正常
    E_ALLOCATE,
    E_ENV_KEY,
    E_SYNTAX,
    E_PIPE,
} t_status;


typedef struct s_info
{
    t_ast_node *ast;//root
    t_list *env_map;//線形リストのhead
    char **envp;//envpのポインタ配列
    int is_env_updated;//envpが最新のものかどうか


    char cwd[MAX_WORD_LEN];
    t_status status; //グローバル変数として持てなかったら

    /* optional info */
} t_info;


t_info *system_init(char **env);
void system_deinit(t_info *info);

#endif