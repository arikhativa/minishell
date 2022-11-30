/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:26:56 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/14 13:09:15 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_bool	is_end_of_var_name(char c)
{
	if (SPACE_CHAR == c
		|| MINUS_CHAR == c
		|| EQUAL_CHAR == c
		|| SINGLE_QUOTE_CHAR == c
		|| DOUBLE_QUOTE_CHAR == c
		|| '\0' == c)
		return (TRUE);
	return (FALSE);
}

t_bool	ready_to_expand(char *str, int i)
{
	if (i < 0)
		return (FALSE);
	if (is_redirect(str + i))
		return (TRUE);
	return (FALSE);
}
