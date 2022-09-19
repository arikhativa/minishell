/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:03:53 by yoav              #+#    #+#             */
/*   Updated: 2022/09/18 15:39:12 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_util.h"

t_bool	is_redirect_symbol(char *s)
{
	return (is_drl(s) || is_drr(s) || is_rl(s) || is_rr(s));
}

char	*skip_redirect_symbol(char *s)
{
	if (is_drl(s) || is_drr(s))
		return (s + 2);
	return (s + 1);
}

t_bool	is_redirect(char *s)
{
	while (ft_isdigit(*s))
		++s;
	return (is_redirect_symbol(s));
}

t_bool	is_semi_redirect(char *s)
{
	while (ft_isdigit(*s))
		++s;
	s = skip_redirect_symbol(s);
	if (*s)
		return (FALSE);
	return (TRUE);
}
