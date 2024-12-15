#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROMPT "minishell> "

// Signal handler for interactive mode
void	handle_signal(int sig)
{
	if (sig == SIGINT) // Ctrl-C
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT) // Ctrl-backslash
	{
		; // Do nothing
	}
}

int	main(void)
{
	char	*input;

	// Set up signal handlers
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
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
		{
			add_history(input);
		}
		// 未完成のコマンドチェック（例: 開いた引用符が閉じられていない）
		if (input[0] == '\'' || input[0] == '"')
		{
			printf("Error: Unmatched quotes.\n");
			free(input);
			continue ;
		}
		// ユーザーの入力内容を出力（デバッグ目的）
		printf("You entered: %s\n", input);
		// メモリ解放
		free(input);
	}
	// readlineの履歴をクリア
	rl_clear_history();
	return (0);
}
