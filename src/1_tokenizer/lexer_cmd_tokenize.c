/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd_tokenize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:51:46 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 19:43:46 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_system.h"

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
static t_cmd_token	*create_cmd_token(t_info *info, t_token_type type,
		char *path, char **args)
{
	t_cmd_token	*cmd;

	cmd = xmalloc(sizeof(t_cmd_token), info);
	cmd->type = type;
	cmd->path = path;
	cmd->args = args;
	return (cmd);
}

/**
 * @brief t_cmd_token *cmdをt_info *info->token_listに追加
 *
 * @details
 * t_cmd_token *cmdをt_info *info->token_listに追加
 * ft_lstnew()できなかった場合、cmd->path, cmd->args,
 * cmdをfreeし、system_exit()を呼びE_ALLOCATEをセット
 * @param[in] info t_info *
 * @param[in] cmd t_cmd_token *
 */
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

typedef struct s_cmd_seq
{
	t_list			*start;
	t_list			*tmpp;
	t_cmd_token		*cmd;
	char			**args;
	char			*path;
	t_token			*ctk;
}					t_cmd_seq;

static t_status	process_cmd_sequence(t_info *info, t_list **cur)
{
	t_cmd_seq	seq;
	size_t		count;
	size_t		i;

	count = 0;
	seq.start = *cur;
	while (*cur && ((t_token *)(*cur)->data)->type == TT_CMD)
	{
		count++;
		*cur = (*cur)->next;
	}
	seq.args = xmalloc(sizeof(char *) * (count + 1), info);
	seq.tmpp = seq.start;
	i = 0;
	while (i < count)
	{
		seq.ctk = (t_token *)seq.tmpp->data;
		seq.args[i] = ft_strdup(seq.ctk->value);
		seq.tmpp = seq.tmpp->next;
		i++;
	}
	seq.args[count] = NULL;
	seq.path = ft_strdup(seq.args[0]);
	seq.cmd = create_cmd_token(info, TT_CMD, seq.path, seq.args);
	if (!seq.cmd)
		return (E_ALLOCATE);
	add_cmd_token_to_info(info, seq.cmd);
	return (E_NONE);
}

static t_status	process_single_token(t_info *info, t_token_type type)
{
	t_cmd_token	*cmd;

	cmd = create_cmd_token(info, type, NULL, NULL);
	if (!cmd)
		return (E_ALLOCATE);
	add_cmd_token_to_info(info, cmd);
	return (E_NONE);
}

/**
 * @brief トークン列tokensをt_cmd_token列info->token_listに変換
 *
 * @details
 * トークン列tokensをt_cmd_token列info->token_listに変換
 * TT_CMD, TT_PIPE, TT_AND_AND, TT_OR_OR, TT_LPAREN, TT_RPAREN
 * のみを対象とし、TT_REDIRECT系やTT_EOF, TT_ERRORはパーサー段階で扱う
 * ここでは簡易的にスキップもしくはエラー処理を行う
 *
 * @param[in] tokens トークン列
 * @param[in] info t_info *
 *
 * @retval E_NONE 正常
 * @retval E_ALLOCATE メモリーの割り当てに失敗
 */

t_status	convert_tokens_to_cmd_tokens(t_list *tokens, t_info *info)
{
	t_list		*cur;
	t_token		*tk;
	t_status	st;

	cur = tokens;
	while (cur)
	{
		tk = (t_token *)cur->data;
		if (tk->type == TT_CMD)
		{
			st = process_cmd_sequence(info, &cur);
			if (st != E_NONE)
				return (st);
			continue ;
		}
		if (tk->type == TT_PIPE || tk->type == TT_AND_AND
			|| tk->type == TT_OR_OR || tk->type == TT_LPAREN
			|| tk->type == TT_RPAREN)
		{
			st = process_single_token(info, tk->type);
			if (st != E_NONE)
				return (st);
			cur = cur->next;
		}
		else
			cur = cur->next;
	}
	return (E_NONE);
}
