
#ifndef AST_H
# define AST_H

// typedef enum e_token_type
// {
// 	TOKEN_WORD,
// 	TOKEN_PIPE,          //|
// 	TOKEN_REDIR_IN,      //<
// 	TOKEN_REDIR_OUT,     //>
// 	TOKEN_REDIR_APPEND,  //>>
// 	TOKEN_REDIR_HEREDOC, //<<
// 	TOKEN_ENV_VAR,       //$
// }						t_token_type;

# include "lexer.h"

// typedef struct s_token
// {
// 	t_token_type		type;
// 	char				*value;
// 	struct s_token		*next;
// }						t_token;

typedef struct s_ast_node
{
	t_token_type		type;
	// int                    file_type;
	char				**args;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}						t_ast_node;

/**** funcs ****/
// parseする関数（汎用的なものはここ、minishellでしか使えないものはft_parse.hに?）
//走査する関数

#endif