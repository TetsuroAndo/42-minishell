/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:50:22 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 15:26:43 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include <stdlib.h>
#include <string.h>

static char	**_append_arg(char **args, size_t *count, char *new_arg)
{
	char	**res;

	res = realloc(args, sizeof(char *) * (*count + 2));
	if (!res)
	{
		free(new_arg);
		return (args); // 簡易的なエラー処理（本当は全体エラーを扱うべき）
	}
	res[*count] = new_arg;
	(*count)++;
	res[*count] = NULL;
	return (res);
}

static t_cmd_token	*_append_cmd(t_cmd_token *cmds, size_t *count,
		t_cmd_token new_cmd)
{
	t_cmd_token	*res;

	res = realloc(cmds, sizeof(t_cmd_token) * (*count + 1));
	if (!res)
	{
		// 簡易エラー処理（real projectではエラー対応が必要）
		return (cmds);
	}
	res[*count] = new_cmd;
	(*count)++;
	return (res);
}

t_cmd_token	*_parse_commands(t_token *tokens)
{
	t_cmd_token	*cmds;
	size_t		cmd_count;
	t_cmd_token	current_cmd;
	char		**arg_list;
	size_t		arg_count;
	t_cmd_token	pipe_cmd;
	char		*val;
	t_cmd_token	eof_cmd;

	cmds = NULL;
	cmd_count = 0;
	memset(&current_cmd, 0, sizeof(current_cmd));
	current_cmd.type = TT_CMD;
	arg_list = NULL;
	arg_count = 0;
	for (int i = 0; tokens[i].type != TT_EOF && tokens[i].type != TT_ERROR; i++)
	{
		if (tokens[i].type == TT_PIPE)
		{
			// 現在までのコマンドを確定
			if (current_cmd.path != NULL)
			{
				current_cmd.args = arg_list;
				cmds = _append_cmd(cmds, &cmd_count, current_cmd);
			}
			else
			{
				// pathがNULLなのにPIPEが来た → 空コマンドだが、とりあえずスキップ
				// arg_listをfree
				if (arg_list)
				{
					for (size_t k = 0; arg_list[k]; k++)
						free(arg_list[k]);
					free(arg_list);
				}
			}
			// PIPEコマンド挿入
			memset(&pipe_cmd, 0, sizeof(pipe_cmd));
			pipe_cmd.type = TT_PIPE;
			cmds = _append_cmd(cmds, &cmd_count, pipe_cmd);
			// 次コマンド初期化
			memset(&current_cmd, 0, sizeof(current_cmd));
			current_cmd.type = TT_CMD;
			arg_list = NULL;
			arg_count = 0;
		}
		else if (tokens[i].type == TT_CMD)
		{
			// CMDトークン時
			val = tokens[i].value;
			if (current_cmd.path == NULL)
			{
				// 最初のCMDはpath
				current_cmd.path = strdup(val);
				arg_list = _append_arg(arg_list, &arg_count, strdup(val));
			}
			else
			{
				// 2回目以降のCMDトークンは引数
				arg_list = _append_arg(arg_list, &arg_count, strdup(val));
			}
		}
		else if (tokens[i].type == TT_REDIRECT_IN
			|| tokens[i].type == TT_REDIRECT_OUT || tokens[i].type == TT_APPEND
			|| tokens[i].type == TT_HEREDOC)
		{
			// リダイレクト系は今は未対応なのでスキップ
			// TODO: 将来ここでcurrent_cmdへredirectionを追加する実装が必要
			continue ;
		}
		else
		{
			// その他未想定のトークンはスキップするか、エラーとして扱うか
			// とりあえずスキップ
			continue ;
		}
	}
	// 最後のコマンド確定
	if (current_cmd.path != NULL)
	{
		current_cmd.args = arg_list;
		cmds = _append_cmd(cmds, &cmd_count, current_cmd);
	}
	else
	{
		// pathがNULLの場合、arg_listを解放
		if (arg_list)
		{
			for (size_t k = 0; arg_list[k]; k++)
				free(arg_list[k]);
			free(arg_list);
		}
	}
	// 終端(EOF)トークンを挿入
	eof_cmd = (t_cmd_token){TT_EOF, NULL, NULL};
	cmds = _append_cmd(cmds, &cmd_count, eof_cmd);
	return (cmds);
}
