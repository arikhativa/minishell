/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:01:33 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/01 10:58:14 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_error_code	builtin_exit(t_shell_op *sp, t_cmd *c)
{
	sp->run = FALSE;
	c->builtin_ret_val = SUCCESS;
	ft_putstr_fd("exit\n", c->out_stream);
	return (SUCCESS);
}
