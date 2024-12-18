/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:51:53 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 18:59:47 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

/**
 * @brief トークンリストの最後にエラートークンを追加
 *
 * @param tokens トークンリスト
 * @return エラートークンを追加したトークンリスト
 *
 * TT_ERROR型トークンを作成し、tokensに追加する
 */
t_list	*add_error_token(t_list *tokens)
{
	t_token	err;

	err = make_token(TT_ERROR, NULL);
	tokens = token_list_add(tokens, err);
	return (tokens);
}
