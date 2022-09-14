/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:52:42 by yoav              #+#    #+#             */
/*   Updated: 2022/09/14 09:51:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_op.h"

t_error_code	shell_op_create(t_shell_op **ret)
{
	*ret = ft_calloc(1, sizeof(t_shell_op));
	if (!(*ret))
		return (ALLOCATION_ERROR);
	return (SUCCESS);
}

void	shell_op_destroy(t_shell_op **sp)
{
	if ((*sp)->input)
		tab_destroy(&((*sp)->input));
	if ((*sp)->token_list)
		token_list_destroy(&((*sp)->token_list));
	ft_bzero(*sp, sizeof(t_shell_op));
	free(*sp);
	*sp = NULL;
}
