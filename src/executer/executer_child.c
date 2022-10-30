/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/10/31 16:48:18 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// TODO do something with stt = execve() on err
// TODO err print
t_error_code	executer_child_logic(t_cmd *c, char **env)
{
	t_error_code	err;
	int				stt;

	err = piper_child_dup_if_needed(c);
	if (SUCCESS != err)
		return (err);
	err = redirecter_child_dup_if_needed(c);
	if (SUCCESS != err)
		return (err);
	stt = execve(c->exec_path, c->argv, env);
	if (ERROR == stt)
		error_code_print(3, strerror(errno), ": ", cmd_get_cmd(c));
	return (SUCCESS);
}
