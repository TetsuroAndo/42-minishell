/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:53:59 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 19:25:00 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "ft_token.h"
# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define MAX_WORD_LEN 2048
// minishell.hと分けなくても良いかもしれないけど
//他のdirでこっちinfo.hはincludeできるけだminishell.hはinclude禁止にするとテストが捗りそう

typedef struct s_info
{
	t_ast_node *ast;    // root
	t_list *env_map;    //線形リストのhead
	char **envp;        // envpのポインタ配列
	int is_env_updated; // envpが最新のものかどうか
	char	cwd[MAX_WORD_LEN];
	t_status status; //グローバル変数として持てなかったら
	char	*pathes;
	int		is_pathes_update;
	/* optional info */
}			t_info;

t_info		*system_init(char **env);
void		system_deinit(t_info *info);

#endif
