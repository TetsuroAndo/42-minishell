/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:44:20 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 20:24:38 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "ft_system.h"
# include "ft_token.h"

typedef struct s_lexer
{
	const char	*input;
	size_t		pos;
}				t_lexer;

/* <---------------- 外部インターフェース ----------------> */
t_status		xlexer(t_info *info);

/* <---------------- 内部用プロトタイプ ----------------> */

/* lexer_cmd_token*/
t_status		convert_tokens_to_cmd_tokens(t_list *tokens, t_info *info);

/* lexer_error.c */
t_list			*add_error_token(t_list *tokens);

/* lexer_loop.c */
t_list			*lexer_loop(t_lexer *lx);

/* lexer_quote.c */
char			*read_quoted_word(t_lexer *lx, char quote);

/* lexer_read_word.c */
char			*read_word(t_lexer *lx);

/* lexer_token_manage.c */
t_token			make_token(t_token_type type, const char *val);
void			free_token(void *content);
t_list			*token_list_add(t_list *lst, t_token tk);

/* lexer_utils.c */
t_cmd_token		*create_cmd_token(t_info *info, t_token_type type, char *path,
					char **args);
void			skip_spaces(t_lexer *lx);
int				is_special_char(char c);
int				is_token_special(t_token_type type);
int				is_token_redirect(t_token_type type);

/* lexer_wildcards */
void			expand_wildcards(t_list **tokens, t_info *info);

// test
void			print_cmd_tokens(const t_list *tokens);
void			free_cmd_token(void *data);

#endif