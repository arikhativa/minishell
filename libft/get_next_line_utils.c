/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:35:25 by yoav              #+#    #+#             */
/*   Updated: 2022/10/19 13:57:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "libft.h"

void	swap_ptr(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strndup(char *s, size_t size)
{
	size_t	i;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		ret[i] = s[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_join_str(char *buff, char *str)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = ft_strlen(buff);
	j = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, buff, i);
	ft_memcpy((ret + i), str, j);
	ret[i + j] = '\0';
	if (NULL != buff)
		free(buff);
	free(str);
	return (ret);
}
