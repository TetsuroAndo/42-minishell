/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:10:00 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 17:34:49 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_system.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_cmd_token	*get_parsed_commands_line(char *line)
{
	t_token		*tokens;
	t_cmd_token	*cmds;

	if (!line)
		return (NULL);
	tokens = _lexer(line);
	if (!tokens)
	{
		fprintf(stderr, "Failed to tokenize input\n");
		return (NULL);
	}
	cmds = _parse_commands(tokens);
	if (!cmds)
	{
		fprintf(stderr, "Failed to parse commands\n");
		free_tokens(tokens);
		return (NULL);
	}
	free_tokens(tokens);
	return (cmds);
}
