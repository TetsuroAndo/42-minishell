#include "ft_lexer.h"
#include "ft_token.h"
#include "libft.h"

void	free_cmd_token(void *data)
{
	t_cmd_token	*cmd;

	cmd = (t_cmd_token *)data;
	if (!cmd)
		return ;
	if (cmd->path)
		free(cmd->path);
	if (cmd->args)
		ft_strs_clear(cmd->args); // libftの拡張関数などでchar**解放
	free(cmd);
}

void	print_cmd_tokens(const t_list *tokens)
{
	const t_cmd_token	*cmd;
	char				*typestr;
	int					i;

	while (tokens)
	{
		cmd = (const t_cmd_token *)tokens->data;
		switch (cmd->type)
		{
		case TT_CMD:
			typestr = "CMD";
			break ;
		case TT_PIPE:
			typestr = "PIPE";
			break ;
		case TT_AND_AND:
			typestr = "&&";
			break ;
		case TT_OR_OR:
			typestr = "||";
			break ;
		case TT_LPAREN:
			typestr = "(";
			break ;
		case TT_RPAREN:
			typestr = ")";
			break ;
		case TT_REDIRECT_IN:
			typestr = "<";
			break ;
		case TT_REDIRECT_OUT:
			typestr = ">";
			break ;
		case TT_APPEND:
			typestr = ">>";
			break ;
		case TT_HEREDOC:
			typestr = "<<";
			break ;
		case TT_ERROR:
			typestr = "ERROR";
			break ;
		case TT_EOF:
			typestr = "EOF";
			break ;
		default:
			typestr = "UNKNOWN";
			break ;
		}
		ft_printf("CMD_TOKEN = {type: %s, path: \"%s\", args: ", typestr,
			(cmd->path ? cmd->path : "(null)"));
		if (cmd->args)
		{
			i = 0;
			ft_printf("[\"");
			ft_putstrs_fd(cmd->args, "\", \"", STDOUT_FILENO);
			ft_printf("\"]");
		}
		else
			ft_printf("(null)");
		ft_printf("}\n");
		tokens = tokens->next;
	}
}
