/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:00:44 by yoav              #+#    #+#             */
/*   Updated: 2022/09/17 12:32:46 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_list.h"

static int	inter_func(t_dll *node, void *param)
{
	(void)param;
	printf("{ ");
	token_print(node->value);
	printf(" }");
	if (node->next)
		printf(", ");
	return (SUCCESS);
}

void	token_list_print(t_token_list *lst)
{
	printf("[ ");
	dll_iterate(lst->tok_lst, inter_func, NULL);
	printf(" ]\n");
}
