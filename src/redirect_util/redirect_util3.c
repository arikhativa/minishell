/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:03:53 by yoav              #+#    #+#             */
/*   Updated: 2022/09/22 17:25:12 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_util.h"

t_bool	redirect_util_is_input(char *s)
{
	return (RL_CHAR == *s);
}

t_bool	redirect_util_is_output(char *s)
{
	return (RR_CHAR == *s);
}
