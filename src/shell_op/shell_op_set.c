/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_op_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:27:25 by yoav              #+#    #+#             */
/*   Updated: 2022/09/14 10:04:52 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_op.h"

void	shell_op_set_input(t_shell_op *sp, char **input)
{
	sp->input = input;
}

void	shell_op_set_token_list(t_shell_op *sp, t_token_list *tok_lst)
{
	sp->token_list = tok_lst;
}
