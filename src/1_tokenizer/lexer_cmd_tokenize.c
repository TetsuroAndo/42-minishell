/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd_tokenize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:51:46 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 18:23:01 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_system.h"

static t_cmd_token	*create_cmd_token(t_token_type type, char *path,
		char **args)
{
	t_cmd_token	*cmd;

	cmd = malloc(sizeof(t_cmd_token));
	if (!cmd)
		return (NULL);
	cmd->type = type;
	cmd->path = path;
	cmd->args = args;
	return (cmd);
}

static void	add_cmd_token_to_info(t_info *info, t_cmd_token *cmd)
{
	t_list	*node;

	node = ft_lstnew(cmd);
	if (!node)
	{
		// エラー処理
		// path, args解放必要
		if (cmd->path)
			free(cmd->path);
		if (cmd->args)
			ft_strs_clear(cmd->args);
		free(cmd);
		system_exit(info, E_ALLOCATE);
	}
	ft_lstadd_back(&info->token_list, node);
}

t_status	convert_tokens_to_cmd_tokens(t_list *tokens, t_info *info)
{
	t_list		*cur;
	t_token		*tk;
	size_t		count;
	t_list		*start;
	char		**args;
	t_list		*tmpp;
	t_token		*ctk;
	char		*path;
	t_cmd_token	*cmd;

	cur = tokens;
	while (cur)
	{
		tk = (t_token *)cur->data;
		if (tk->type == TT_CMD)
		{
			// CMD列を収集
			count = 0;
			start = cur;
			while (cur && ((t_token *)cur->data)->type == TT_CMD)
			{
				count++;
				cur = cur->next;
			}
			args = xmalloc(sizeof(char *) * (count + 1), info);
			tmpp = start;
			for (size_t i = 0; i < count; i++)
			{
				ctk = (t_token *)tmpp->data;
				args[i] = ft_strdup(ctk->value);
				tmpp = tmpp->next;
			}
			args[count] = NULL;
			path = ft_strdup(args[0]);
			cmd = create_cmd_token(TT_CMD, path, args);
			if (!cmd)
				return (E_ALLOCATE);
			add_cmd_token_to_info(info, cmd);
			continue ;
		}
		else if (tk->type == TT_PIPE || tk->type == TT_AND_AND
			|| tk->type == TT_OR_OR || tk->type == TT_LPAREN
			|| tk->type == TT_RPAREN)
		{
			cmd = create_cmd_token(tk->type, NULL, NULL);
			if (!cmd)
				return (E_ALLOCATE);
			add_cmd_token_to_info(info, cmd);
			cur = cur->next;
		}
		else
		{
			// TT_REDIRECT系やTT_EOF, TT_ERRORがくる場合、パーサー段階で扱うか
			// ここでは簡易的にスキップまたはエラー処理を行う
			cur = cur->next;
		}
	}
	return (E_NONE);
}
