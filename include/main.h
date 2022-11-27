/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:19:46 by yoav              #+#    #+#             */
/*   Updated: 2022/11/20 17:12:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <fcntl.h>

# include "error_code.h"
# include "macro.h"
# include "executer.h"
# include "commander.h"
# include "parser.h"
# include "laxer.h"
# include "shell_op.h"
# include "mini_signal.h"
# include "reader.h"
# include "piper.h"
# include "cleaner.h"
# include "mode_mngr.h"

typedef t_error_code	(*t_read_input)(t_shell_op *sp);

t_error_code	handle_input(t_shell_op *sp, t_read_input read_func);
t_error_code	handle_valid_input(t_shell_op *sp);
t_error_code	internal_loop(t_shell_op *sp, t_read_input read_func);
t_error_code	internal_flow(char *cli_input, char **envp, \
	t_read_input read_func);

#endif
