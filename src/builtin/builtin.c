/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:17:05 by yoav              #+#    #+#             */
/*   Updated: 2022/10/30 12:38:13 by yoav             ###   ########.fr       */
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

	if (!word)
		return (FALSE);
	ret = TRUE;
	ret *= ft_strcmp(word, BUILTIN_EXIT_STR);
	return (!ret);
}

t_builtin	builtin_get_func(char *word)
{
	if (!word)
		return (NULL);
	if (!ft_strcmp(word, BUILTIN_EXIT_STR))
		return (builtin_exit);
	return (NULL);
}

t_error_code	builtin_exit(t_shell_op *sp, t_cmd *c)
{
	(void)c;
	sp->run = FALSE;
	c->builtin_ret_val = SUCCESS;
	printf("exit\n");
	return (SUCCESS);
}
