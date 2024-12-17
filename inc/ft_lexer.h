/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:44:20 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 20:11:43 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "ft_system.h"

typedef struct s_lexer
{
	const char	*input;
	size_t		pos;
}				t_lexer;

t_token			*lexer(const char *input);
t_token			*token_list_add(t_token *list, size_t *count, t_token newtok);

#endif