/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/10/09 12:24:08 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDER_H
# define COMMANDER_H

# include "error_code.h"
# include "cmd.h"
# include "shell_op.h"
# include "cmd_list.h"
# include "macro.h"
# include "laxer.h"

t_error_code	commander_create_cmds(t_shell_op *sp);
t_dll			*commander_skip_to_next_cmd(t_dll *n);
t_bool			is_cmd(t_dll *n);

#endif
