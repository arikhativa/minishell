/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:46:10 by yoav              #+#    #+#             */
/*   Updated: 2022/10/06 09:52:18 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <stdlib.h>

# include "error_code.h"
# include "tab.h"
# include "macro.h"

// t_cmd
// argv:
// A "shallow tab" -> the strings are not owned by t_cmd
// meaning t_cmd does not alloc the strings mem or free it.
// only the list of ptrs is handled
typedef struct s_cmd
{
	char		**argv;
	char		**env;
	int			stt;
}	t_cmd;

t_error_code	cmd_create(t_cmd **ret);
void			cmd_destroy(t_cmd **cmd);
t_error_code	cmd_add_arg(t_cmd *c, char *arg);

#endif
