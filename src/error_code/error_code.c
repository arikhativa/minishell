/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:42:34 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 14:20:46 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_code.h"

void	error_code_print(int size, ...)
{
	va_list			list;
	char			*s;
	int				i;

	ft_putstr_fd(MINISHELL_STR, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	va_start(list, size);
	i = 0;
	while (i < size)
	{
		s = va_arg(list, char *);
		ft_putstr_fd(s, STDERR_FILENO);
		++i;
	}
	va_end(list);
	ft_putstr_fd(NEW_LINE_STR, STDERR_FILENO);
}

static void	error_code_print_msg(char *msg, t_error_code err)
{
	ft_putstr_fd(MINISHELL_STR, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putnbr_fd(err, STDERR_FILENO);
	ft_putstr_fd(NEW_LINE_STR, STDERR_FILENO);
}

t_error_code	error_code_print_internal_err(t_error_code err)
{
	if (ERROR == err)
		error_code_print_msg("ERROR", err);
	else if (SUCCESS == err)
		error_code_print_msg("SUCCESS", err);
	else if (ALLOCATION_ERROR == err)
		error_code_print_msg("ALLOCATION_ERROR", err);
	else if (NO_BUILTIN_ERROR == err)
		error_code_print_msg("NO_BUILTIN_ERROR", err);
	else if (NEW_PROC_ERROR == err)
		error_code_print_msg("NEW_PROC_ERROR", err);
	else if (CLOSE_ERROR == err)
		error_code_print_msg("CLOSE_ERROR", err);
	else if (OPEN_ERROR == err)
		error_code_print_msg("OPEN_ERROR", err);
	else
		error_code_print_msg("UNKNOWN_ERROR", err);
	return (err);
}
