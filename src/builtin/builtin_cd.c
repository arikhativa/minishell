/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:34:33 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/08 10:47:38 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_error_code	get_dir(t_shell_op *sp, char *new_dir)
{
	t_error_code	err;
	char			*tmp;

	err = chdir(new_dir);
	if (SUCCESS != err)
		return (err);
	tmp = getcwd(NULL, 0);
	if (!ft_strcmp(tmp, env_getvar(sp->envp, PWD_VAR)))
	{
		free(tmp);
		return (SUCCESS);
	}
	env_setvar(&sp->envp, OLDPWD_VAR, env_getvar(sp->envp, PWD_VAR));
	env_setvar(&sp->envp, PWD_VAR, tmp);
	free(tmp);
	return (SUCCESS);
}

t_error_code	builtin_cd(t_shell_op *sp, t_cmd *c)
{
	c->builtin_ret_val = 0;
	if (1 == tab_count(c->argv))
	{
		if (SUCCESS != get_dir(sp, env_getvar(sp->envp, HOME_VAR)))
			c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
		return (SUCCESS);
	}
	if (SUCCESS != get_dir(sp, *(c->argv + 1)))
	{
		error_code_print(3, CD_ERR_STR, *(c->argv + 1), CD_INVALID_PATH_STR);
		c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
	}
	return (SUCCESS);
}
