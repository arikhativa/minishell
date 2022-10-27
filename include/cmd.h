/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:46:10 by yoav              #+#    #+#             */
/*   Updated: 2022/10/27 11:38:10 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <stdlib.h>
# include <sys/types.h>

# include "redirect_list.h"
# include "error_code.h"
# include "tab.h"
# include "macro.h"

typedef enum e_cmd_stt
{
	OK = 0,
	CMD_NOT_FOUND,
	PREM_DENIED,
}	t_cmd_stt;

// t_cmd
// argv:
// A "shallow tab" -> the strings are not owned by t_cmd
// meaning t_cmd does not alloc the strings mem or free it.
// only the list of ptrs is handled
typedef struct s_cmd
{
	char			*exec_path;
	char			**argv;
	t_cmd_stt		stt;
	pid_t			pid;
	int				builtin_ret_val;
	t_redirect_list	*redirect;
}	t_cmd;

t_error_code	cmd_create(t_cmd **ret);
void			cmd_destroy(t_cmd **cmd);
t_error_code	cmd_add_arg(t_cmd *c, char *arg);
char			*cmd_get_cmd(t_cmd *c);

#endif
