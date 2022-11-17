/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_wrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:57:09 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 12:18:45 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dup_wrapper.h"

t_error_code	dup_wrapper(int oldfd, int newfd)
{
	if (ERROR == dup2(oldfd, newfd))
		return (ERROR);
	return (SUCCESS);
}
