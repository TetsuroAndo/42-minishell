#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_system.h"
#include "libft.h"
#include "minishell.h"
#include <stdio.h>

/**
 * @brief 再帰的にASTを出力する関数
 * @param node ASTノード
 * @param depth インデント用深さ
 */
static void	print_ast(const t_ast_node *node, int depth)
{
	t_redirect	*r;

	if (!node)
		return ;
	// インデント出力用
	for (int i = 0; i < depth; i++)
		printf("  ");
	// パイプノードかコマンドノードか判別
	if (node->type == TT_PIPE)
	{
		printf("AST_PIPELINE\n");
		// left
		print_ast(node->u_data.pipeline.left, depth + 1);
		// right
		print_ast(node->u_data.pipeline.right, depth + 1);
	}
	else
	{
		// コマンドノードと仮定
		printf("AST_COMMAND: name=%s\n", node->u_data.command.name);
		// 引数
		for (int i = 0; node->u_data.command.args
			&& node->u_data.command.args[i]; i++)
		{
			for (int j = 0; j < depth + 1; j++)
				printf("  ");
			printf("arg[%d]: %s\n", i, node->u_data.command.args[i]);
		}
		// リダイレクト
		r = node->u_data.command.redirects;
		while (r)
		{
			for (int j = 0; j < depth + 1; j++)
				printf("  ");
			printf("redirect: ");
			switch (r->type)
			{
			case TT_REDIRECT_IN:
				printf("< %s\n", r->filename);
				break ;
			case TT_REDIRECT_OUT:
				printf("> %s\n", r->filename);
				break ;
			case TT_APPEND:
				printf(">> %s\n", r->filename);
				break ;
			case TT_HEREDOC:
				printf("<< %s\n", r->filename);
				break ;
			default:
				printf("Unknown redirect\n");
				break ;
			}
			r = r->next;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info		*info;
	t_status	st;

	(void)argc;
	(void)envp;
	// 環境の初期化（必要ならenvpを利用して）
	info = system_init();
	// ここではinfo->env_mapなどの初期化も必要なら対応
	// 例えば:
	// info->env_map = xlst_from_strs(envp, info);
	// argv[1]にテストしたいコマンドラインを指定
	// 例: "./test_parser \"echo hello | cat < infile > outfile\""
	if (argv[1])
		info->source_line = ft_strdup(argv[1]);
	else
		info->source_line = ft_strdup("echo hello world");
	// 字句解析およびトークナイズ(xlexer)を実行
	// xlexer(info)内でinfo->token_listがt_cmd_tokenリストになる想定
	st = xlexer(info);
	if (st != E_NONE)
	{
		fprintf(stderr, "Lexer error\n");
		system_exit(info, st);
	}
	// パーサ実行
	st = parse_tokens(info);
	if (st != E_NONE)
	{
		fprintf(stderr, "Parser error\n");
		system_exit(info, st);
	}
	// AST出力
	if (info->ast)
	{
		printf("=== AST ===\n");
		print_ast(info->ast, 0);
	}
	else
	{
		printf("No AST generated.\n");
	}
	// 終了処理
	ast_free(info->ast);
	info->ast = NULL;
	system_exit(info, 0);
	return (0);
}
