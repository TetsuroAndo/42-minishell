/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:51:53 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 00:51:54 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lexer.h"
#include "libft.h"

t_list	*add_error_token(t_list *tokens)
{
	t_token	err;

	err = make_token(TT_ERROR, NULL);
	tokens = token_list_add(tokens, err);
	return (tokens);
}
