/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:53:59 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 17:11:05 by teando           ###   ########.fr       */
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

# define MAX_PATH 2048
// # define MAX_FD 1024

typedef struct s_info
{
	char		*source_line;
	t_list		*token_list;
	t_ast_node	*ast;
	t_list		*env_map;
	char		cwd[MAX_PATH];
	// int			files[MAX_FD];
	t_status	status;
}				t_info;

t_info			*system_init(void);
void			system_deinit(t_info *info);

void			system_exit(t_info *info, t_status status);

t_status		xabsolute_path(char *dstpath, char *srcpath, char *envpathes,
					int mode);

char			*read_command_line(const char *prompt);

/**** **** **** ****ALLOCATE**** **** **** ****/
void			*xmalloc(size_t size, t_info *info);
t_list			*xlstnew(char *data, t_info *info);
t_list			*xlst_from_strs(char **strs, t_info *info);
char			**xlst_to_strs(t_list *lst, t_info *info);

#endif
