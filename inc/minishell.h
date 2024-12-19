/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:41:18 by teando            #+#    #+#             */
/*   Updated: 2024/12/18 22:31:00 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_builtin.h"
# include "ft_env.h"
# include "ft_executor.h"
# include "ft_lexer.h"
# include "ft_parser.h"
# include "ft_redirect.h"
# include "ft_signals.h"
# include "ft_system.h"
# include "ft_token.h"

# define PROMPT "minishell> "

/* <----------- 0_core: exec_builtin -----------> */
// int		is_builtin(char *cmd);
// int		exec_builtin(void);

/* <----------- 6_signals -----------> */
// void	init_signals(void);

/* <----------- 7_builtin -----------> */

#endif