/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:26:56 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/13 12:35:19 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_bool	is_print_dollar(char *s, int i, t_quote q_stt)
{
	char	c;

	if (1 == i)
	{
		c = s[1];
		if (IN_QUOTE == q_stt.double_quote && DOUBLE_QUOTE_CHAR == c)
			return (TRUE);
		if (!ft_isalnum(c) && UNDERSCORE_CHAR != c && DOUBLE_QUOTE_CHAR != c \
			&& SINGLE_QUOTE_CHAR != c)
			return (TRUE);
	}
	return (FALSE);
}

int	expander_is_space(char c)
{
	return (TAB_CHAR == c || NEW_LINE_CHAR == c || SPACE_CHAR == c
		|| '\v' == c || '\f' == c || '\r' == c);
}
