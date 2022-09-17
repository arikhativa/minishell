/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:01:22 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 15:38:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_util.h"

t_bool	is_rr(char *s)
{
	if (!is_drr(s))
		return (RR_CHAR == *s);
	return (FALSE);
}

t_bool	is_rl(char *s)
{
	if (!is_drl(s))
		return (RL_CHAR == *s);
	return (FALSE);
}

t_bool	is_drr(char *s)
{
	if (*s && *(s + 1))
		return (RR_CHAR == *s && RR_CHAR == *(s + 1));
	return (FALSE);
}

t_bool	is_drl(char *s)
{
	if (*s && *(s + 1))
		return (RL_CHAR == *s && RL_CHAR == *(s + 1));
	return (FALSE);
}
