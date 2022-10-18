/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:42:34 by yoav              #+#    #+#             */
/*   Updated: 2022/10/18 14:47:19 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_code.h"

void	error_code_print_msg(char *msg)
{
	ft_putstr_fd(MINISHELL_STR, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

void	error_code_print(t_error_code err)
{
	if (ERROR == err)
		error_code_print_msg("ERROR");
	else if (SUCCESS == err)
		error_code_print_msg("SUCCESS");
	else if (ALLOCATION_ERROR == err)
		error_code_print_msg("ALLOCATION_ERROR");
	else
		error_code_print_msg("UNKNOWN_ERROR");
}
