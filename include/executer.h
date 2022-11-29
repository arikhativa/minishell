/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:20:11 by yoav              #+#    #+#             */
/*   Updated: 2022/11/29 12:50:18 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "redirecter.h"
# include "macro.h"
# include "cmd.h"
# include "shell_op.h"
# include "piper.h"
# include "builtin.h"
# include "error_code.h"

t_error_code	executer_run_cmd(t_shell_op *sp, t_cmd *c);
t_error_code	executer_child_logic(t_shell_op *sp, t_cmd *c);
t_error_code	executer_run_all_cmds(t_shell_op *sp);
t_error_code	executer_run_builtin(t_shell_op *sp, t_cmd *c);

#endif
