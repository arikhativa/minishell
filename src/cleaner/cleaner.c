/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:04:03 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 15:12:22 by yoav             ###   ########.fr       */
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
	}
}
