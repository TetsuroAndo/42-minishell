/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:44:20 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 17:21:24 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "ft_system.h"
# include <stddef.h>

typedef struct s_lexer
{
	const char		*input;
	size_t			pos;
}					t_lexer;

t_cmd_token			*get_parsed_commands_line(char *line);
t_token				*_lexer(const char *input);
t_cmd_token			*_parse_commands(t_token *tokens);
void				free_cmds(t_cmd_token *cmds);
void				free_tokens(t_token *tokens);

#endif