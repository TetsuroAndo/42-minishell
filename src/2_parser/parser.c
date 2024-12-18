/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:38:04 by teando            #+#    #+#             */
/*   Updated: 2024/12/19 02:09:52 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief リダイレクトトークンを1つパースする
 *
 * @param cur 現在位置
 * @param info
 * @return t_redirect* パース成功時は新規作成のリダイレクトノード, 失敗時NULL
 */
static t_redirect	*parse_one_redirect(t_list **cur, t_info *info)
{
	t_cmd_token	*redir_tk;
	t_cmd_token	*file_tk;
	t_redirect	*r;

	redir_tk = get_next_cmd_token(cur);
	if (!redir_tk)
		return (NULL);
	// 次はファイル名がTT_CMDで来ることが期待される
	file_tk = get_next_cmd_token(cur);
	if (!file_tk || file_tk->type != TT_CMD || !file_tk->args
		|| !file_tk->args[0])
		return (NULL);
	r = xmalloc(sizeof(t_redirect), info);
	r->type = redir_tk->type; // ここではt_token_typeをそのまま使用
	r->filename = ft_strdup(file_tk->args[0]);
	r->next = NULL;
	return (r);
}

/**
 * @brief コマンドノードをパースする
 *
 * 最初にTT_CMDトークンからコマンド名・引数を抽出し、
 * 続いてリダイレクトトークン(TT_REDIRECT_IN/OUT/APPEND/HEREDOC)があれば処理する。
 *
 * @param cur
 * @param info
 * @return t_ast_node* 成功時:コマンドノードポインタ, 失敗時NULL
 */
static t_ast_node	*parse_command_node(t_list **cur, t_info *info)
{
	t_cmd_token	*cmd_tk;
	t_ast_node	*node;
	t_redirect	*redir_list;
	t_redirect	*last_redir;
	t_cmd_token	*next_tk;
	t_redirect	*nr;

	if (!cur || !*cur)
		return (NULL);
	cmd_tk = (t_cmd_token *)(*cur)->data;
	if (!cmd_tk || cmd_tk->type != TT_CMD || !cmd_tk->args || !cmd_tk->args[0])
		return (NULL);
	// コマンドノード作成
	node = xmalloc(sizeof(t_ast_node), info);
	// コマンドノードでは、typeはTT_CMDで表現するが、後続でTT_PIPEがない限りコマンドノードとして扱う
	// ここではコマンド自体には特別なAST用enumは無しでt_token_typeを流用し、typeはTT_CMD等を代入する
	node->type = cmd_tk->type; // 基本TT_CMD
	node->u_data.command.name = ft_strdup(cmd_tk->args[0]);
	node->u_data.command.args = ft_strs_dup(cmd_tk->args);
	node->u_data.command.redirects = NULL;
	*cur = (*cur)->next; // CMDトークン消費
	redir_list = NULL;
	last_redir = NULL;
	// リダイレクト等の処理
	while (*cur)
	{
		next_tk = (t_cmd_token *)(*cur)->data;
		if (!next_tk)
			break ;
		if (next_tk->type == TT_REDIRECT_IN || next_tk->type == TT_REDIRECT_OUT
			|| next_tk->type == TT_APPEND || next_tk->type == TT_HEREDOC)
		{
			nr = parse_one_redirect(cur, info);
			if (!nr)
			{
				ast_free(node);
				return (NULL);
			}
			if (!redir_list)
				redir_list = nr;
			else
				last_redir->next = nr;
			last_redir = nr;
		}
		else
		{
			// パイプや他のトークンが来たらコマンド定義は終了
			break ;
		}
	}
	node->u_data.command.redirects = redir_list;
	return (node);
}

/**
 * @brief パイプライン（コマンドとパイプを構造化）をパースする
 *
 * grammar(簡易):
 * pipeline : command ( '|' pipeline )?
 * command : cmd_token {redirect}*
 *
 * @param cur
 * @param info
 * @return t_ast_node*
 */
static t_ast_node	*parse_pipeline(t_list **cur, t_info *info);

static t_ast_node	*parse_command(t_list **cur, t_info *info)
{
	return (parse_command_node(cur, info));
}

static t_ast_node	*parse_pipeline(t_list **cur, t_info *info)
{
	t_ast_node	*left;
	t_cmd_token	*tk;
	t_ast_node	*right;
	t_ast_node	*pipe_node;

	left = parse_command(cur, info);
	if (!left)
		return (NULL);
	while (*cur)
	{
		tk = (t_cmd_token *)(*cur)->data;
		if (tk && tk->type == TT_PIPE)
		{
			// パイプノード
			*cur = (*cur)->next; // '|' を消費
			right = parse_pipeline(cur, info);
			if (!right)
			{
				ast_free(left);
				return (NULL);
			}
			pipe_node = xmalloc(sizeof(t_ast_node), info);
			pipe_node->type = TT_PIPE; // パイプノードであることをtypeで示す
			pipe_node->u_data.pipeline.left = left;
			pipe_node->u_data.pipeline.right = right;
			left = pipe_node;
		}
		else
		{
			// パイプ以外のトークンが来たらpipelineは終了
			break ;
		}
	}
	return (left);
}

t_status	parse_tokens(t_info *info)
{
	t_list		*cur;
	t_ast_node	*root;

	if (!info->token_list)
		return (E_NONE); // 空の入力等の場合、特にASTなしでOK
	cur = info->token_list;
	root = parse_pipeline(&cur, info);
	if (!root)
		return (E_SYNTAX);
	info->ast = root;
	return (E_NONE);
}
