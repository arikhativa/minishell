/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:26:18 by yoav              #+#    #+#             */
/*   Updated: 2022/12/11 14:55:54 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SIGNAL_H
# define MINI_SIGNAL_H

# include <stdio.h>
# include <readline/readline.h>
# include <signal.h>

# include "macro.h"
# include "error_code.h"
# include "shell_op.h"

t_error_code	mini_signal_interactive_mode(void);
t_error_code	mini_signal_disable(void);
t_error_code	mini_signal_set_child(void);
t_error_code	mini_signal_set_heredoc(void);

#endif
