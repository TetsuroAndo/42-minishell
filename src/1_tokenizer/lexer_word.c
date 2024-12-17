/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:56:11 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 20:01:16 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

typedef struct s_word
{
	char	*word;
	char	*part;
	char	quote;
}			t_word;

static char	*append_str(char *orig, char *addition)
{
	char	*temp;

	temp = ft_strjoin(orig, addition);
	free(orig);
	free(addition);
	return (temp);
}

static char	*read_normal_segment(t_lexer *lx)
{
	size_t	pos_start;
	size_t	seg_len;
	char	*segment;

	pos_start = lx->pos;
	while (lx->input[lx->pos] && !ft_isspace((unsigned char)lx->input[lx->pos])
		&& lx->input[lx->pos] != '"' && lx->input[lx->pos] != '\''
		&& lx->input[lx->pos] != '|' && lx->input[lx->pos] != '<'
		&& lx->input[lx->pos] != '>')
	{
		lx->pos++;
	}
	seg_len = lx->pos - pos_start;
	segment = ft_substr(lx->input, pos_start, seg_len);
	return (segment);
}

static char	*read_word(t_lexer *lx)
{
	t_word	wd;

	wd.word = ft_strdup("");
	while (lx->input[lx->pos] && !ft_isspace((unsigned char)lx->input[lx->pos])
		&& lx->input[lx->pos] != '|' && lx->input[lx->pos] != '<'
		&& lx->input[lx->pos] != '>')
	{
		if (lx->input[lx->pos] == '"' || lx->input[lx->pos] == '\'')
		{
			wd.quote = lx->input[lx->pos++];
			wd.part = read_quoted_word(lx, wd.quote);
			if (!wd.part)
				return (free(wd.word), NULL);
			wd.word = append_str(wd.word, wd.part);
		}
		else
		{
			wd.part = read_normal_segment(lx);
			wd.word = append_str(wd.word, wd.part);
		}
	}
	if (wd.word[0] == '\0')
		return (free(wd.word), NULL);
	return (wd.word);
}
