/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:42:34 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 09:45:03 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_code.h"

void	internal_error_print(const char *msg, t_error_code err)
{
	printf("%s: %d\n", msg, err);
}

void	error_code_print(t_error_code err)
{
	if (ERROR == err)
		internal_error_print("ERROR", err);
	else if (SUCCESS == err)
		internal_error_print("SUCCESS", err);
	else if (ALLOCATION_ERROR == err)
		internal_error_print("ALLOCATION_ERROR", err);
	else
		internal_error_print("UNKNOWN_ERROR", err);
}
