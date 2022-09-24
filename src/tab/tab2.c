/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:08:43 by yoav              #+#    #+#             */
/*   Updated: 2022/10/06 10:03:27 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"

static void	tab_copy(char **dest, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
}

static size_t	tab_count(char **t)
{
	size_t	i;

	i = 0;
	while (t[i])
		++i;
	return (i);
}

void	tab_print(char **t)
{
	int	i;

	i = 0;
	printf("[ ");
	while (t[i])
	{
		printf("'%s' ", t[i]);
		++i;
		if (t[i])
			printf(",");
	}
	printf("]\n");
}

t_error_code	tab_add(char ***tab, char *s)
{
	t_error_code	err;
	size_t			size;
	char			**old_tab;
	char			**new_tab;

	old_tab = *tab;
	size = tab_count(old_tab);
	err = tab_create(&new_tab, size + 1);
	if (SUCCESS != err)
		return (err);
	tab_copy(new_tab, old_tab);
	new_tab[size] = s;
	new_tab[size + 1] = NULL;
	*tab = new_tab;
	free(old_tab);
	return (SUCCESS);
}
