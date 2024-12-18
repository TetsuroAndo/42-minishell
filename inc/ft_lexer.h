/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:44:20 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 17:02:47 by teando           ###   ########.fr       */
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
t_list			*lexer(const char *input);
void			free_token(void *content);

/* lexer_loop.c */
t_list			*lexer_loop(t_lexer *lx);

/* lexer_utils.c */
void			skip_spaces(t_lexer *lx);
int				is_special_char(char c);

/* lexer_read_word.c */
char			*read_word(t_lexer *lx);

/* lexer_quote.c */
char			*read_quoted_word(t_lexer *lx, char quote);

/* lexer_token_manage.c */
t_token			make_token(t_token_type type, const char *val);
t_list			*token_list_add(t_list *lst, t_token tk);

/* lexer_error.c */
t_list			*add_error_token(t_list *tokens);

/* lexer_check_redirect.c */
t_token_type	check_redirect_type(t_lexer *lx, char first);

#endif