/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:20:11 by yoav              #+#    #+#             */
/*   Updated: 2022/10/24 10:25:45 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "macro.h"
# include "cmd.h"
# include "shell_op.h"
# include "builtin.h"
# include "error_code.h"

# define EXEC_CMD_NOT_FOUND_STR	"command not found: "
# define EXEC_PREM_ERR_STR		"permission denied: "

t_error_code	executer_run_cmd(t_cmd *c, char **env);
t_error_code	executer_run_all_cmds(t_shell_op *sp);

#endif
