/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:26:56 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/10 17:52:15 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_bool	is_print_dollar(char *s, int i, t_quote q_stt)
{
	if (1 == i)
	{
		if (IN_QUOTE == q_stt.double_quote && DOUBLE_QUOTE_CHAR == s[1])
			return (TRUE);
		if (!s[1] || expander_is_space(s[1]))
			return (TRUE);
	}
	return (FALSE);
}

int	expander_is_space(char c)
{
	return (TAB_CHAR == c || NEW_LINE_CHAR == c || SPACE_CHAR == c
		|| '\v' == c || '\f' == c || '\r' == c);
}
