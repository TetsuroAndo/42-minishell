/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:52:58 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 21:05:44 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

/**
 * @brief t_cmd_token *cmdを生成
 *
 * @details
 * t_cmd_token *cmdを生成
 * type, path, argsをメンバ変数に保持
 *
 * @param[in] type t_token_type
 * @param[in] path const char *
 * @param[in] args const char **
 *
 * @retval t_cmd_token *cmd
 */
t_cmd_token	*create_cmd_token(t_info *info, t_token_type type, char *path,
		char **args)
{
	t_cmd_token	*cmd;

	cmd = xmalloc(sizeof(t_cmd_token), info);
	cmd->type = type;
	cmd->path = path;
	cmd->args = args;
	return (cmd);
}

void	skip_spaces(t_lexer *lx)
{
	while (lx->input[lx->pos] && ft_isspace((unsigned char)lx->input[lx->pos]))
		lx->pos++;
}

int	is_special_char(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '(' || c == ')' || c == '&')
		return (1);
	return (0);
}

int	is_token_special(t_token_type type)
{
	return (type == TT_PIPE || type == TT_AND_AND || type == TT_OR_OR
		|| type == TT_LPAREN || type == TT_RPAREN);
}

int	is_token_redirect(t_token_type type)
{
	return (type == TT_REDIRECT_IN || type == TT_REDIRECT_OUT
		|| type == TT_APPEND || type == TT_HEREDOC);
}
