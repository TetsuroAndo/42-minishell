/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:47:26 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 12:19:33 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "lexer.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
  補助関数群
*/
static void skip_spaces(t_lexer *lx)
{
	while (isspace((unsigned char)lx->input[lx->pos]))
		lx->pos++;
}

static t_token make_token(t_token_type type, const char *value)
{
	t_token tok;

	tok.type = type;
	tok.value = NULL;
	if (value)
		tok.value = strdup(value);
	return (tok);
}

static int is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static char peek_char(t_lexer *lx)
{
	return (lx->input[lx->pos]);
}

static char advance_char(t_lexer *lx)
{
	char c;

	c = lx->input[lx->pos];
	if (c != '\0')
		lx->pos++;
	return (c);
}

static t_token_type check_redirect_type(t_lexer *lx, char first)
{
	char next;

	// firstは'<'または'>'
	next = lx->input[lx->pos];
	if (first == '<' && next == '<')
	{
		lx->pos++;
		return (TT_HEREDOC);
	}
	if (first == '>' && next == '>')
	{
		lx->pos++;
		return (TT_APPEND);
	}
	if (first == '<')
		return (TT_REDIRECT_IN);
	return (TT_REDIRECT_OUT);
}

/*
  クォート処理：
  クォート開始文字('\'または'"')が来たら、そのクォートが閉じるまで読み込み続ける
  クォートはvalueに含めず除去する
*/
static char *read_quoted_word(t_lexer *lx, char quote_char)
{
	size_t length;

	size_t start = lx->pos; // クォート開始後
	while (peek_char(lx) != '\0' && peek_char(lx) != quote_char)
		lx->pos++;
	if (peek_char(lx) == '\0')
	{
		// クォート閉じてない
		return (NULL);
	}
	// peek_char(lx) == quote_charで閉じた
	length = lx->pos - start;
	// クォートを閉じる
	lx->pos++;
	return (ft_substr(lx->input, start, length));
}

/*
  単語読み込み：
  スペース、特殊文字、クォート以外を読み続ける
  クォートがあればクォート内を取得し連結
*/
static char *read_word(t_lexer *lx)
{
	char *word;
	char *temp;
	char quote;
	char *quoted_part;
	size_t pos_start;
	size_t seg_len;
	char *segment;

	word = NULL;
	word = strdup(""); // 最初は空文字から始める
	while (peek_char(lx) != '\0' && !isspace((unsigned char)peek_char(lx)) && !is_special_char(peek_char(lx)))
	{
		if (peek_char(lx) == '"' || peek_char(lx) == '\'')
		{
			quote = advance_char(lx);
			quoted_part = read_quoted_word(lx, quote);
			if (!quoted_part)
			{
				free(word);
				return (NULL); // エラー(未閉クォート)
			}
			// quoted_partをwordに連結
			temp = ft_strjoin(word, quoted_part);
			free(word);
			free(quoted_part);
			word = temp;
		}
		else
		{
			// 通常文字
			pos_start = lx->pos;
			while (peek_char(lx) && !isspace((unsigned char)peek_char(lx)) && !is_special_char(peek_char(lx)) && peek_char(lx) != '"' && peek_char(lx) != '\'')
			{
				lx->pos++;
			}
			seg_len = lx->pos - pos_start;
			segment = ft_substr(lx->input, pos_start, seg_len);
			temp = ft_strjoin(word, segment);
			free(word);
			free(segment);
			word = temp;
		}
	}
	if (strlen(word) == 0)
		return (free(word), NULL);
	return (word);
}

static t_token *token_list_add(t_token *list, size_t *count, t_token newtok)
{
	t_token *res;

	res = realloc(list, sizeof(t_token) * (*count + 2));
	if (!res)
	{
		free(newtok.value);
		return (list);
	}
	res[*count] = newtok;
	*count = *count + 1;
	res[*count] = (t_token){TT_EOF, NULL};
	return (res);
}

t_token *lexer(const char *input)
{
	t_lexer lx;
	t_token *tokens;
	size_t count;
	char c;
	t_token_type ttype;
	char *w;

	tokens = NULL;
	count = 0;
	lx.input = input;
	lx.pos = 0;
	tokens = malloc(sizeof(t_token));
	tokens[0].type = TT_EOF;
	tokens[0].value = NULL;
	skip_spaces(&lx);
	while (peek_char(&lx) != '\0')
	{
		if (is_special_char(peek_char(&lx)))
		{
			c = advance_char(&lx);
			ttype = TT_CMD;
			if (c == '|')
				ttype = TT_PIPE;
			else if (c == '<' || c == '>')
				ttype = check_redirect_type(&lx, c);
			tokens = token_list_add(tokens, &count, make_token(ttype, NULL));
		}
		else if (!isspace((unsigned char)peek_char(&lx)))
		{
			w = read_word(&lx);
			if (!w)
			{
				// エラー(未閉クォートなど)
				// エラー時にはTT_ERRORトークンを追加して終了
				tokens = token_list_add(tokens, &count, make_token(TT_ERROR, NULL));
				break;
			}
			tokens = token_list_add(tokens, &count, make_token(TT_CMD, w));
			free(w);
		}
		skip_spaces(&lx);
	}
	return (tokens);
}

void free_tokens(t_token *tokens)
{
	int i;

	i = 0;
	while (tokens[i].type != TT_EOF && tokens[i].type != TT_ERROR)
		free(tokens[i++].value);
	free(tokens);
}
