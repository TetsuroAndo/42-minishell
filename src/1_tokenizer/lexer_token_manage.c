/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_manage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:52:03 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 19:09:18 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

/**
 * @brief make_tokenはトークン(t_token)を生成する
 *
 * @details
 * トークン(t_token)を生成
 * type, valueをメンバ変数に保持
 * valueはvalがNULLの場合はNULL、valがNULLでない場合はft_strdup(val)で
 * 生成された文字列を保持
 *
 * @param[in] type t_token_type
 * @param[in] val const char *
 *
 * @retval t_token *tk
 */
t_token	make_token(t_token_type type, const char *val)
{
	t_token	tk;

	tk.type = type;
	tk.value = NULL;
	if (val)
		tk.value = ft_strdup(val);
	return (tk);
}

void	free_token(void *ct)
{
	t_token	*t;

	t = (t_token *)ct;
	if (t)
	{
		free(t->value);
		free(t);
	}
}

/**
 * @brief トークンリストに新しいトークンを追加
 *
 * @param lst トークンリスト
 * @param tk 追加するトークン
 * @return トークンリスト
 *
 * トークンリストlstにtkを追加したトークンリストを返す
 * その際、tkのvalueを複製する
 * また、tkのvalueがNULLの場合は何もしない
 * エラーが発生した場合はlstをクリアしてNULLを返す
 */
t_list	*token_list_add(t_list *lst, t_token tk)
{
	t_token	*dup;
	t_list	*new;

	dup = malloc(sizeof(t_token));
	if (!dup)
	{
		ft_lstclear(&lst, free_token);
		return (NULL);
	}
	*dup = tk;
	new = ft_lstnew(dup);
	if (!new)
	{
		free_token(dup);
		ft_lstclear(&lst, free_token);
		return (NULL);
	}
	ft_lstadd_back(&lst, new);
	return (lst);
}
