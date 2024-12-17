/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:53:59 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 00:04:48 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

#include "ft_token.h"
#include "libft.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PATH 2048
// # define MAX_FD 1024
// minishell.hと分けなくても良いかもしれないけど
// 他のdirでこっちinfo.hはincludeできるけだminishell.hはinclude禁止にするとテストが捗りそう

typedef struct s_info
{
	t_ast_node *ast; // root
	t_list *env_map; // 線形リストのhead
	char cwd[MAX_PATH];
	// int			files[MAX_FD];
	t_status status;
} t_info;

t_info *system_init(char **env);
void system_deinit(t_info *info);
void *xmalloc(size_t size, t_info *info);
void system_exit(t_info *info, t_status status);

/* <----------- 0_system: readline -----------> */
char *read_command_line(const char *prompt);

#endif
