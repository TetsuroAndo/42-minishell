#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROMPT "minishell> "

int	main(void)
{
	char	*input;

	while (1)
	{
		// readline関数でプロンプトを表示し、ユーザー入力を取得
		input = readline(PROMPT);
		// 入力がNULLの場合（Ctrl-DなどでEOFが送られた場合）、シェルを終了
		if (!input)
		{
			printf("\nExiting minishell.\n");
			break ;
		}
		// 入力が空でない場合は履歴に追加
		if (*input)
			add_history(input);
		// ユーザーの入力内容を出力（デバッグ目的）
		printf("You entered: %s\n", input);
		free(input);
	}
	// readlineの履歴をクリア
	rl_clear_history();
	return (0);
}
