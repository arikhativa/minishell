/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:46:10 by yoav              #+#    #+#             */
/*   Updated: 2022/12/12 09:58:30 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <stdlib.h>
# include <sys/types.h>

# include "redirect_list.h"
# include "error_code.h"
# include "pipe_pair.h"
# include "tab.h"
# include "macro.h"
# include "heredoc_utils.h"

typedef enum e_cmd_stt
{
	OK = 0,
	REDIRECT_ERROR = 1,
	PREM_DENIED,
	CMD_EMPTY,
	CMD_IS_DIR = 126,
	CMD_NOT_FOUND = 127,
	CMD_EXIT_SIG_INT = 130,
	CMD_EXIT_SIG_QUIT = 131,
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
	t_pipe_pair		*pp;
	int				in_stream;
	int				out_stream;
}	t_cmd;

t_error_code	cmd_create(t_cmd **ret);
void			cmd_destroy(t_cmd **cmd);
t_error_code	cmd_add_arg(t_cmd *c, char *arg);
char			*cmd_get_cmd(t_cmd *c);
void			cmd_set_pipe_in(t_cmd *c, int fd);
void			cmd_set_pipe_out(t_cmd *c, int fd);
void			cmd_set_stream(t_cmd *c, t_redirect *r);

#endif
