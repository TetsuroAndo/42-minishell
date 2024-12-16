/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:41:18 by teando            #+#    #+#             */
/*   Updated: 2024/12/16 17:53:01 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

#include "system.h"

# define PROMPT "minishell> "

/* <----------- 0_core: exec_builtin -----------> */
int		is_builtin(char *cmd);
int		exec_builtin(void);

/* <----------- 6_signals -----------> */
void	init_signals(void);

/* <----------- 7_builtin -----------> */
void	builtin_pwd(const t_info *info);

#endif