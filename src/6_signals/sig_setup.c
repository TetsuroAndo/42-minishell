/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:35:45 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 14:51:34 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

/*
 * SIGINT (Ctrl-C)時に新しい行と新しいプロンプトを表示するためのハンドラ。
 * bash類似動作：
 * - 対話中にCtrl-C：新しい行を表示してプロンプト再表示
 * - 実行中のコマンドがあればそれを中断する挙動(後々実装)
 * 今は最低限プロンプト行に戻す動作のみ。
 */

static void sigint_handler(int signum)
{
	(void)signum;
	// readline用再描画:
	// 公式ドキュメントによれば、rl_replace_line("", 0)とrl_on_new_line()、rl_redisplay()で再描画
	// 現在の行を空行にして、新しいプロンプトへ
	if (write(STDOUT_FILENO, "\n", 1) == -1)
		return; // シグナルハンドラ内なのでエラー処理は最小限に
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void sigquit_handler(int signum)
{
	(void)signum;
	// Ctrl-\ では何もしない(bash互換)
	// ここでは空実装
}

void init_signals(void)
{
	struct sigaction sa_int;
	struct sigaction sa_quit;

	sa_int.sa_handler = sigint_handler;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = sigquit_handler;
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa_quit, NULL);
	// Ctrl-DはreadlineがNULL返すので、特別にsignal handler設定は不要
}
