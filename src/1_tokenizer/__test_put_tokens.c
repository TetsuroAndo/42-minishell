#include "ft_lexer.h"
#include "ft_token.h"
#include "libft.h"

static const char *get_token_type_str(t_token_type type)
{
	if (type == TT_CMD)
		return ("CMD");
	if (type == TT_PIPE)
		return ("PIPE");
	if (type == TT_REDIRECT_IN)
		return ("REDIRECT_IN");
	if (type == TT_REDIRECT_OUT)
		return ("REDIRECT_OUT");
	if (type == TT_APPEND)
		return ("APPEND");
	if (type == TT_HEREDOC)
		return ("HEREDOC");
	if (type == TT_ERROR)
		return ("ERROR");
	return ("EOF");
}

void print_tokens(const t_list *tokens)
{
	t_token *token;

	if (!tokens)
	{
		printf("No tokens to print\n");
		return;
	}
	while (tokens)
	{
		if (!tokens->data)
		{
			printf("Warning: NULL token data encountered\n");
			tokens = tokens->next;
			continue;
		}
		token = (t_token *)tokens->data;
		printf("Token = {type: %s, value: \"%s\"}\n",
			   get_token_type_str(token->type),
			   (token->value) ? token->value : "(null)");
		tokens = tokens->next;
	}
}
