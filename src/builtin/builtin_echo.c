/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:39:25 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/12/10 17:55:07 by yrabby           ###   ########.fr       */
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
		if (*(tab + i))
			ft_putstr_fd(" ", fd);
	}
	if (nl)
		ft_putstr_fd("\n", fd);
}

static t_bool	is_flag(char *s)
{
	if (MINUS_CHAR != *s)
		return (FALSE);
	++s;
	if (N_CHAR != *s)
		return (FALSE);
	++s;
	while (N_CHAR == *s)
		++s;
	if (*s)
		return (FALSE);
	return (TRUE);
}

static int	get_print_index_and_flag(int *is_nl, char **tab)
{
	int	i;

	i = 1;
	while (tab[i] && is_flag(tab[i]))
	{
		*is_nl = FALSE;
		++i;
	}
	return (i);
}

t_error_code	builtin_echo(t_shell_op *sp, t_cmd *c)
{
	int	print_index;
	int	is_nl;

	(void)sp;
	if (!*(c->argv + 1))
	{
		ft_putstr_fd("\n", c->out_stream);
		return (SUCCESS);
	}
	is_nl = TRUE;
	print_index = get_print_index_and_flag(&is_nl, c->argv);
	print_string(c->argv + print_index, is_nl, c->out_stream);
	c->builtin_ret_val = SUCCESS;
	return (SUCCESS);
}
