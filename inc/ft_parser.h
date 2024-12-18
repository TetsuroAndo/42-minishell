/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:27:53 by teando            #+#    #+#             */
/*   Updated: 2024/12/19 02:01:35 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "ft_system.h"

/**
 * @brief パーサのメインインターフェース
 *
 * info->token_list (t_list: cmd_tokenリスト)を基にASTを構築する
 * 成功時: info->ast にルートASTノードを格納し E_NONE返す
 * 失敗時: エラーコード返す (E_SYNTAX等)
 */
t_status	parse_tokens(t_info *info);
void		ast_free(t_ast_node *node);

/* **** **** **** **** **** **** **** **** **** **** **** **** */
t_cmd_token	*get_next_cmd_token(t_list **cur);

#endif