/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:39:25 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/18 23:48:59 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	print_string(char **tab, t_bool nl, int fd)
{
	int	i;

	i = 0;
	while (*(tab + i))
	{
		ft_putstr_fd(*(tab + i++), fd);
		ft_putstr_fd(" ", fd);
	}
	if (nl)
		ft_putstr_fd("\n", fd);
}

t_error_code	builtin_echo(t_shell_op *sp, t_cmd *c)
{
	(void)sp;
	if (!*(c->argv + 1))
	{
		ft_putstr_fd("\n", c->out_stream);
		return (SUCCESS);
	}
	if (!ft_strcmp(*(c->argv + 1), "-n"))
		print_string(c->argv + 2, 0, c->out_stream);
	else
		print_string(c->argv + 1, 1, c->out_stream);
	c->builtin_ret_val = 0;
	return (SUCCESS);
}
