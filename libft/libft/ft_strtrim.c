/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:48:13 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 13:57:00 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int	get_start(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i] && ft_strchr(set, s[i]))
		++i;
	return (i);
}

static int	get_end(char const *s, char const *set)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0 && ft_strchr(set, s[i]))
		--i;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end < start)
		return (ft_strdup(""));
	ret = ft_substr(s1, start, (end - start + 1));
	return (ret);
}
