#include "ft_lexer.h"

void	print_cmd_tokens(const t_cmd_token *cmds)
{
	int i, j;
	printf("token modified_line[...]:\n");
	for (i = 0; cmds[i].type != TT_EOF && cmds[i].type != TT_ERROR; i++)
	{
		printf("token%d = {", i + 1);
		if (cmds[i].type == TT_CMD)
		{
			printf("CMD, \"%s\", \"", cmds[i].path ? cmds[i].path : "");
			if (cmds[i].args)
			{
				for (j = 0; cmds[i].args[j] != NULL; j++)
				{
					printf("%s", cmds[i].args[j]);
					if (cmds[i].args[j + 1] != NULL)
						printf(" ");
				}
			}
			printf("\"}\n");
		}
		else if (cmds[i].type == TT_PIPE)
			printf("PIPE, NULL, NULL}\n");
		else
			printf("OTHER, NULL, NULL}\n");
	}
}
