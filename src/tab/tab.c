/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:53:02 by yoav              #+#    #+#             */
/*   Updated: 2022/09/17 21:40:49 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"

void	tab_print(char **input_table)
{
	int	i;

	i = 0;
	if (input_table)
	{
		while (*(input_table + i))
		{
			printf("[%d]%s$\n", i, *(input_table + i));
			i++;
		}
	}
}

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
