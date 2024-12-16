#ifndef MINISHELL_INFO_H
#define MINISHELL_INFO_H
#include "ft_env.h"
#include "ft_ast.h"


//minishell.hと分けなくても良いかもしれないけど
//他のdirでこっちinfo.hはincludeできるけだminishell.hはinclude禁止にするとテストが捗りそう

typedef struct s_info
{
    t_ast_node ast;//root
    t_btmap env;//root

    char pwd[MAX_WORD_LEN];

    /* optional info */
    //t_err exitstatus; //グローバル変数として持てなかったら
} t_info;
#endif