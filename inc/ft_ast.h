#ifndef AST_H
#define AST_H

#include "minishell.h"
#include "lexer.h"

typedef struct s_ast_node
{
	// t_token_type type;
	//  int                    file_type;
	char **args;
	struct s_ast_node *left;
	struct s_ast_node *right;
} t_ast_node;

/**** funcs ****/
// parseする関数（汎用的なものはここ、minishellでしか使えないものはft_parse.hに?）
// 走査する関数

#endif