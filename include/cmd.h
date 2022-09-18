/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:46:10 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 16:07:22 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <stdlib.h>

# include "error_code.h"
# include "arg_list.h"

typedef struct s_cmd
{
	t_arg_list	*args;
	int			in;
	int			out;
	int			err;
	int			stt;
}	t_cmd;

t_error_code	cmd_create(t_cmd **ret);
void			cmd_destroy(t_cmd **cmd);
t_error_code	cmd_add_arg(t_cmd *c, char *arg);

#endif
