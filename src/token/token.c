/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:38:31 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 10:45:20 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_error_code	token_create(t_token **ret, char *ptr, t_token_type type)
{
	*ret = ft_calloc(1, sizeof(t_token));
	if (!*ret)
		return (ALLOCATION_ERROR);
	(*ret)->type = type;
	(*ret)->value = ptr;
	return (SUCCESS);
}

void	token_destroy(t_token **t)
{
	ft_bzero(*t, sizeof(t_token));
	free(*t);
	*t = NULL;
}
