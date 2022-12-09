/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:39:51 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/01 10:58:44 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_error_code	builtin_unset(t_shell_op *sp, t_cmd *c)
{
	(void)sp;
	(void)c;
	env_unsetvar(sp->envp, *(c->argv + 1));
	c->builtin_ret_val = 0;
	return (SUCCESS);
}
