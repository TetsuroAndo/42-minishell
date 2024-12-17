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
	int i;
	const t_list *current;
	const t_token *token;

	i = 0;
	current = tokens;
	while (current)
	{
		token = (const t_token *)current->data;
		ft_printf("Token[%d]: type=%s", i, get_token_type_str(token->type));
		if (token->value)
			ft_printf(", value='%s'", token->value);
		ft_printf("\n");
		if (token->type == TT_EOF)
			break;
		current = current->next;
		i++;
	}
}
