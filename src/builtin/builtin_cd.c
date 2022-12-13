/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:34:33 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/12 10:39:27 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	*get_pwd_var(t_shell_op *sp)
{
	char	*ret;

	ret = env_getvar(sp->envp, PWD_VAR);
	if (!ret)
		ret = EMPTY_STRING;
	return (ret);
}

static t_error_code	get_dir(t_shell_op *sp, char *new_dir)
{
	t_error_code	err;
	char			*tmp;

	err = chdir(new_dir);
	if (SUCCESS != err)
		return (err);
	tmp = getcwd(NULL, 0);
	if (!ft_strcmp(tmp, get_pwd_var(sp)))
	{
		free(tmp);
		return (SUCCESS);
	}
	env_setvar(&sp->envp, OLDPWD_VAR, get_pwd_var(sp));
	env_setvar(&sp->envp, PWD_VAR, tmp);
	free(tmp);
	return (SUCCESS);
}

static void	home_logic(t_shell_op *sp, t_cmd *c)
{
	char	*home;

	home = env_getvar(sp->envp, HOME_VAR);
	if (!home)
	{
		error_code_print(2, CD_ERR_STR, CD_HOME_ERR_STR);
		c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
		return ;
	}
	if (SUCCESS != get_dir(sp, home))
	{
		error_code_print(3, CD_ERR_STR, home, CD_INVALID_PATH_STR);
		c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
	}
}

t_error_code	builtin_cd(t_shell_op *sp, t_cmd *c)
{
	c->builtin_ret_val = 0;
	if (2 < tab_count(c->argv))
	{
		error_code_print(2, CD_ERR_STR, CD_TOO_MANY_ARGS);
		c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
		return (SUCCESS);
	}
	if (1 == tab_count(c->argv))
	{
		home_logic(sp, c);
		return (SUCCESS);
	}
	if (SUCCESS != get_dir(sp, *(c->argv + 1)))
	{
		error_code_print(3, CD_ERR_STR, *(c->argv + 1), CD_INVALID_PATH_STR);
		c->builtin_ret_val = BUILTIN_RET_VAL_ERROR;
	}
	return (SUCCESS);
}
