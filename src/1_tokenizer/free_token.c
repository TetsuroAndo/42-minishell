/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:29:48 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 16:58:09 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	free_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].type != TT_EOF && tokens[i].type != TT_ERROR)
		free(tokens[i++].value);
	free(tokens);
}

void	free_cmds(t_cmd_token *cmds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!cmds)
		return ;
	while (cmds[i].type != TT_EOF && cmds[i].type != TT_ERROR)
	{
		free(cmds[i].path);
		if (cmds[i].args)
		{
			while (cmds[i].args[j])
				free(cmds[i].args[j++]);
			free(cmds[i].args);
		}
		i++;
	}
	free(cmds);
}
