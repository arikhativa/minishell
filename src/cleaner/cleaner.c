/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:04:03 by yoav              #+#    #+#             */
/*   Updated: 2022/12/14 16:19:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaner.h"

void	cleaner_round_clean(t_shell_op *sp)
{
	if (sp->input)
	{
		tab_deep_destroy(&(sp->input));
		token_list_destroy(&(sp->token_list));
		cmd_list_destroy(&(sp->cmd_list));
		pipe_list_clean(sp->pipe_list);
	}
}

void	cleaner_on_parse_error(t_shell_op *sp)
{
	if (sp->input)
	{
		tab_deep_destroy(&(sp->input));
		token_list_destroy(&(sp->token_list));
	}
}
