/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:05 by yoav              #+#    #+#             */
/*   Updated: 2022/10/18 14:51:44 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// For every new builtin add a line like this:
// ret *= ft_strcmp(word, BUILTIN_XXX_STR);
// if any of them is TRUE then ret will be 0 so !0 -> TRUE
// if none are, then !TRUE -> FALSE
t_bool	is_builtin(char *word)
{
	int	ret;

	ret = TRUE;
	ret *= ft_strcmp(word, BUILTIN_EXIT_STR);
	return (!ret);
}

t_builtin	builtin_get_func(char *word)
{
	if (!ft_strcmp(word, BUILTIN_EXIT_STR))
		return (builtin_exit);
	return (builtin_no_builtin);
}

t_error_code	builtin_no_builtin(t_shell_op *sp, t_cmd *c)
{
	(void)sp;
	(void)c;
	error_code_print_msg(NO_BUILTIN_ERROR);
	return (ERROR);
}

t_error_code	builtin_exit(t_shell_op *sp, t_cmd *c)
{
	(void)c;
	sp->run = FALSE;
	return (SUCCESS);
}
