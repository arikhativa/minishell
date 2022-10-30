/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:19:36 by yoav              #+#    #+#             */
/*   Updated: 2022/10/30 12:32:39 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commander.h"

t_bool	is_cmd(t_dll *n)
{
	t_token	*t;

	t = token_list_get_token(n);
	return (WORD == t->type || REDIRECT == t->type);
}

t_dll	*commander_skip_to_next_cmd(t_dll *n)
{
	t_token	*t;

	t = token_list_get_token(n);
	while (t && n && !is_cmd(n))
	{
		n = n->next;
		t = token_list_get_token(n);
	}
	return (n);
}

void	print_error_if_needed(t_cmd *c)
{
	if (OK != c->stt)
	{
		if (CMD_NOT_FOUND == c->stt)
			error_code_print(2, EXEC_CMD_NOT_FOUND_STR, cmd_get_cmd(c));
		else if (PREM_DENIED == c->stt)
			error_code_print(2, EXEC_PREM_ERR_STR, cmd_get_cmd(c));
	}
}
