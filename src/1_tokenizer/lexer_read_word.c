/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_read_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:52:21 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 00:52:22 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lexer.h"
#include "libft.h"

static char	*append_str(char *orig, char *add)
{
	char *tmp;

	tmp = ft_strjoin(orig, add);
	free(orig);
	free(add);
	return (tmp);
}

static char	*read_normal_segment(t_lexer *lx)
{
	size_t	start;
	char	*seg;

	start = lx->pos;
	while (lx->input[lx->pos] && !ft_isspace((unsigned char)lx->input[lx->pos])
		&& lx->input[lx->pos] != '"' && lx->input[lx->pos] != '\''
		&& !is_special_char(lx->input[lx->pos]))
		lx->pos++;
	seg = ft_substr(lx->input, start, lx->pos - start);
	return (seg);
}

char	*read_word(t_lexer *lx)
{
	char	*word;
	char	*part;
	char	q;

	word = ft_strdup("");
	if (!word)
		return (NULL);
	while (lx->input[lx->pos] && !ft_isspace((unsigned char)lx->input[lx->pos])
		&& !is_special_char(lx->input[lx->pos]))
	{
		if (lx->input[lx->pos] == '"' || lx->input[lx->pos] == '\'')
		{
			q = lx->input[lx->pos++];
			part = read_quoted_word(lx, q);
			if (!part)
				return (free(word), NULL);
			word = append_str(word, part);
		}
		else
			word = append_str(word, read_normal_segment(lx));
		if (!word)
			return (NULL);
	}
	if (word[0] == '\0')
		return (free(word), NULL);
	return (word);
}
