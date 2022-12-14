/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_internal_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/14 16:13:52 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_error_code	get_input_status(t_error_code err)
{
	if (END_OF_TRANSMISSION == err)
	{
		printf("exit\n");
		return (END);
	}
	if ((PIPE_LIMIT_ERROR == err) || (SYNTAX_ERROR == err) || \
		(NO_INPUT == err))
		return (CONTINUE);
	if (EOF_SUCCESS == err)
		return (END);
	return (err);
}

t_error_code	internal_loop(t_shell_op *sp, t_read_input read_func)
{
	t_error_code	err;

	err = SUCCESS;
	while (sp->run && SUCCESS == err)
	{
		err = handle_input(sp, read_func);
		err = get_input_status(err);
		if (CONTINUE == err)
		{
			err = SUCCESS;
			continue ;
		}
		if (END == err)
			return (SUCCESS);
		if (SUCCESS == err)
		{
			err = handle_valid_input(sp);
			if (HEREDOC_SIGNAL_EXIT == err)
			{
				err = SUCCESS;
				continue ;
			}
		}
	}
	return (err);
}
