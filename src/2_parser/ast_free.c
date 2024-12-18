/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:38:58 by teando            #+#    #+#             */
/*   Updated: 2024/12/19 02:21:00 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/**
 * @brief ASTノードを再帰的に解放
 *
 * @param node
 */
static void	ast_free_redirects(t_redirect *r)
{
	t_redirect	*tmp;

	while (r)
	{
		tmp = r->next;
		free(r->filename);
		free(r);
		r = tmp;
	}
}

void	ast_free(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->type == TT_PIPE)
	{
		ast_free(node->u_data.pipeline.left);
		ast_free(node->u_data.pipeline.right);
	}
	else
	{
		// コマンドノード
		free(node->u_data.command.name);
		ft_strs_clear(node->u_data.command.args);
		ast_free_redirects(node->u_data.command.redirects);
	}
	free(node);
}
