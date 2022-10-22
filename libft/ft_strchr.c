/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:20:44 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 13:51:27 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*runner;
	char	ch;

	if (!s)
		return (0);
	ch = (char)c;
	runner = (char *)s;
	while (*runner && *runner != ch)
		++runner;
	if (ch && !*runner)
		return ((char *)0);
	return (runner);
}
