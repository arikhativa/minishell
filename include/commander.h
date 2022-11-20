/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/11/20 11:55:15 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDER_H
# define COMMANDER_H

# include <unistd.h>

# include "builtin.h"
# include "redirecter.h"
# include "error_code.h"
# include "cmd.h"
# include "shell_op.h"
# include "cmd_list.h"
# include "macro.h"
# include "libft.h"
# include "filer.h"
# include "laxer.h"

# define PATH_KEY	"PATH"

t_error_code	commander_create_cmds(t_shell_op *sp);
t_dll			*commander_skip_to_next_cmd(t_dll *n);
t_bool			is_cmd(t_dll *n);
int				commander_init_exec_path(t_dll *elem, void *ptr_path_var_tab);
t_error_code	iter_all_cmds(t_shell_op *sp);
t_error_code	get_path_tab(char ***ret, char **env);
void			print_error_if_needed(t_cmd *c);

#endif
