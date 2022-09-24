/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/10/05 15:39:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// TODO do something with stt = execve() on err
t_error_code	executer_run_cmd(t_cmd *c)
{
	int		stt;
	pid_t	pid;

	pid = fork();
	if (NEW_PROC == pid)
	{
		stt = execve(c->argv[0], c->argv, c->env);
		if (ERROR == stt)
			printf("%s\n", strerror(errno));
	}
	else if (ERROR == pid)
		return (NEW_PROC_ERROR);
	wait(&pid);
	return (SUCCESS);
}
