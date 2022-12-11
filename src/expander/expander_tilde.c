/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_tilde.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:05:08 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/11 10:46:45 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*get_tilde(t_shell_op *sp)
{
	char	*ret;

	ret = env_getvar(sp->envp, HOME_VAR);
	if (!ret)
		ret = EMPTY_STRING;
	return (ret);
}
