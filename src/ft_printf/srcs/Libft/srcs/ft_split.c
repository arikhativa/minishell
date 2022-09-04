/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:42:33 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/24 05:19:57 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	split_count(char const *s, char c)
{
	int	cnt;
	int	aux;

	aux = 0;
	cnt = 0;
	if (*s != c)
		cnt++;
	s++;
	while (*(s + aux))
	{
		if (*(s + aux) != c && *(s + aux - 1) == c)
			cnt++;
		aux++;
	}
	return (cnt);
}

static char	*allocate_substr(char const *s, char c)
{
	char	*sub_splitted;
	int		cnt;

	cnt = 0;
	while (*(s + cnt) != c && *(s + cnt))
		cnt++;
	sub_splitted = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!sub_splitted)
		return (0);
	*(sub_splitted + cnt) = '\0';
	cnt = 0;
	while (*(s + cnt) != c && *(s + cnt))
	{
		*(sub_splitted + cnt) = *(s + cnt);
		cnt++;
	}
	return (sub_splitted);
}

static const char	*skip_sep(const char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static const char	*skip_to_sep(const char *s, char c)
{
	while (*s != c && *s)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		cnt;
	int		aux;

	if (!s)
		return (0);
	if (!ft_strlen(s))
	{
		splitted = (char **)malloc(sizeof(char *));
		*splitted = 0;
		return (splitted);
	}
	aux = 0;
	cnt = split_count(s, c);
	splitted = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!splitted)
		return (0);
	*(splitted + cnt) = NULL;
	while (aux < cnt)
	{
		s = skip_sep(s, c);
		*(splitted + aux++) = allocate_substr(s, c);
		s = skip_to_sep(s, c);
	}
	return (splitted);
}
