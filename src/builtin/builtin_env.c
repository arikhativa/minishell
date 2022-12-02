/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:40:07 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/01 10:58:24 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	print_string(char **str, int fd)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		ft_putstr_fd(*(str + i++), fd);
		ft_putstr_fd("\n", fd);
	}
	ft_putstr_fd("\n", fd);
}

t_error_code	builtin_env(t_shell_op *sp, t_cmd *c)
{
	print_string(sp->envp, c->out_stream);
	c->builtin_ret_val = SUCCESS;
	return (SUCCESS);
}
