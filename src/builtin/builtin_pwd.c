/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:28:23 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/09 10:23:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_error_code	builtin_pwd(t_shell_op *sp, t_cmd *c)
{
	char	*tmp;

	if (1 != tab_count(c->argv))
	{
		c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
		return (SUCCESS);
	}
	c->builtin_ret_val = SUCCESS;
	tmp = getcwd(NULL, 0);
	if (!tmp)
		tmp = ft_strdup(env_getvar(sp->envp, PWD_VAR));
	ft_putstr_fd(tmp, c->out_stream);
	free(tmp);
	ft_putstr_fd("\n", c->out_stream);
	return (SUCCESS);
}
