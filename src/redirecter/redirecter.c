/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:29:37 by yoav              #+#    #+#             */
/*   Updated: 2022/10/30 12:07:30 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirecter.h"

static int	handle_redirect(t_dll *elem, void *param)
{
	t_error_code	err;
	t_redirect		*r;

	(void)param;
	r = elem->value;
	err = open_file(r);
	if (SUCCESS != err)
		error_code_print(3, r->path, ": ", strerror(errno));
	return (err);
}

static int	handle_cmd(t_dll *elem, void *param)
{
	t_error_code	err;
	t_cmd			*c;

	(void)param;
	c = elem->value;
	err = dll_iterate(c->redirect->lst, handle_redirect, NULL);
	if (OPEN_ERROR == err)
	{
		redirect_list_destroy(&(c->redirect));
		c->stt = REDIRECT_ERROR;
		err = SUCCESS;
	}
	return (err);
}

t_error_code	redirecter_setup_files(t_shell_op *sp)
{
	t_error_code	err;

	err = dll_iterate(cmd_list_get_list(shell_op_get_cmd_list(sp)), \
		handle_cmd, NULL);
	if (SUCCESS != err)
		return (err);
	return (SUCCESS);
}

void	redirecter_init_redirect(t_cmd *c, char *symbol, char *path)
{
	if (is_rr(symbol))
		redirect_list_add(c->redirect, path, OUT);
	else if (is_rl(symbol))
		redirect_list_add(c->redirect, path, IN);
	else if (is_drr(symbol))
		redirect_list_add(c->redirect, path, APPEND);
}
