/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:34:19 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 11:54:46 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_shell_info info;

	(void)argc;
	(void)argv;
	// シェル情報構造体を初期化
	info.cwd = getcwd(NULL, 0); // カレントディレクトリの取得
	info.envp = envp;			// とりあえず既存envpをそのまま使う
	info.last_status = 0;
	// メインループ開始
	shell_loop(&info);
	free(info.cwd);
	return (0);
}
