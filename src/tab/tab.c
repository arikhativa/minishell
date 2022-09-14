/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:53:02 by yoav              #+#    #+#             */
/*   Updated: 2022/09/14 09:24:59 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"

t_error_code	tab_create(char	***ret, size_t size)
{
	char	**tab;

	tab = ft_calloc((size + 1), sizeof(char *));
	if (!(tab))
		return (ALLOCATION_ERROR);
	*ret = tab;
	return (SUCCESS);
}

void	tab_destroy(char ***t)
{
	char	**tab;
	size_t	i;

	tab = *t;
	i = 0;
	while (tab[i])
	{
		ft_bzero(tab[i], ft_strlen(tab[i]));
		free(tab[i]);
		tab[i] = NULL;
		++i;
	}
	free(*t);
	*t = NULL;
}
