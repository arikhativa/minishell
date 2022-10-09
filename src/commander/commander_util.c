/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:19:36 by yoav              #+#    #+#             */
/*   Updated: 2022/10/10 14:10:02 by yoav             ###   ########.fr       */
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
