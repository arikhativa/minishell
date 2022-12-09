/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:39:51 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/09 10:23:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_error_code	builtin_unset(t_shell_op *sp, t_cmd *c)
{
	c->builtin_ret_val = SUCCESS;
	if (2 <= tab_count(c->argv))
	{
		if (env_is_key_valid(c->argv[1]))
			env_unsetvar(sp->envp, c->argv[1]);
		else
		{
			error_code_print(3, UNSET_ERR_STR, c->argv[1], \
				UNSET_INVALID_ERR_STR);
			c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
		}
	}
	return (SUCCESS);
}
