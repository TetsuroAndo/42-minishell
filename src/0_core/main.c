/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:34:19 by teando            #+#    #+#             */
/*   Updated: 2024/12/16 15:54:37 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Day1の目標:
 * - readlineでユーザ入力を取得
 * - Ctrl-D（readlineがNULL）でシェル終了
 * - Ctrl-Cで新しいプロンプト表示(実際の処理はsignalハンドラで行う)
 *
 * 環境構築と簡易的なシグナル対応、基本ループのみを実装
 */
int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv; // 未使用
	init_signals();
	while (1)
	{
		line = readline(PROMPT);
		if (!line) // Ctrl-D対応: readlineがNULLを返したら終了
		{
			// 終了処理をここで行う（必要なら）
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		// 入力が空でなければヒストリ追加
		if (*line)
			add_history(line);
		// Day1ではここで入力を即座に処理せず、そのまま表示して終わる(テスト用)
		// 今後lexerやparser実装後にここで処理を呼び出す。
		// 今は動作確認用
		// printf("DEBUG: got line: %s\n", line);
		free(line);
	}
	return (0);
}
