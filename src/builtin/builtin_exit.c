/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:01:33 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/09 10:23:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_error_code	builtin_exit(t_shell_op *sp, t_cmd *c)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (2 < tab_count(c->argv))
	{
		error_code_print(2, EXIT_ERR_STR, EXIT_TOO_MANY_ARGS);
		c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
		return (SUCCESS);
	}
	if (2 == tab_count(c->argv))
	{
		if (!util_is_valid_int(c->argv[1]))
		{
			error_code_print(3, EXIT_ERR_STR, *(c->argv + 1), EXIT_NUM_ERR_STR);
			c->builtin_ret_val = EXIT_NUM_ERR_VALUE;
			return (SUCCESS);
		}
		c->builtin_ret_val = ft_atoi(c->argv[1]);
	}
	else
		c->builtin_ret_val = SUCCESS;
	sp->run = FALSE;
	return (SUCCESS);
}
