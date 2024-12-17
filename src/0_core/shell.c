/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:45:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 10:57:26 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"
#include "minishell_info.h"

extern void	init_signals(void);

static void	print_tokens(const t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].type != TT_EOF && tokens[i].type != TT_ERROR)
	{
		printf("TOKEN: type=%d, value=", tokens[i].type);
		if (tokens[i].value)
			printf("%s\n", tokens[i].value);
		else
			printf("(null)\n");
		i++;
	}
	if (tokens[i].type == TT_ERROR)
		printf("TOKEN ERROR DETECTED\n");
}

void	shell_loop(t_shell_info *info)
{
	char	*line;
	t_token	*tokens;

	(void)info; // 現時点でinfoを使わないならvoidキャスト。ただし将来envやcwdを使う際に活用する。
	init_signals();
	while (1)
	{
		line = read_command_line("minishell> ");
		if (!line)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		// トークナイザを呼び出して入力行をトークン配列に変換
		tokens = lexer(line);
		if (!tokens)
		{
			// lexerがNULL返した場合、メモリ不足などが考えられるがとりあえずエラー処理
			fprintf(stderr, "Failed to tokenize input\n");
			free(line);
			continue ;
		}
		// トークンをデバッグ表示(後でparserへ渡すなど処理を発展可能)
		print_tokens(tokens);
		// エラータイプのトークンがあればここで対処
		// if (tokens[0].type == TT_ERROR)
		//     fprintf(stderr, "Syntax error detected.\n");
		free_tokens(tokens);
		free(line);
	}
}
