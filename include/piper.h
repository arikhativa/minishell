/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:32:26 by yoav              #+#    #+#             */
/*   Updated: 2022/11/22 10:46:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPER_H
# define PIPER_H

# include <unistd.h>

# include "pipe_list.h"
# include "dup_wrapper.h"
# include "pipe_pair.h"
# include "shell_op.h"
# include "cmd_list.h"
# include "cmd.h"
# include "error_code.h"
# include "macro.h"

t_error_code	piper_init_pipes(t_shell_op *sp);
t_error_code	piper_close_pipes(t_shell_op *sp);
t_error_code	piper_child_dup_if_needed(t_cmd *c);
t_error_code	piper_set_stream_if_needed(t_cmd *c);

// is
t_bool			is_one_cmd(t_dll *n);
t_bool			is_first_cmd(t_dll *n);

#endif
