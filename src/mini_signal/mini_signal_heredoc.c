/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signal_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:25:36 by yoav              #+#    #+#             */
/*   Updated: 2022/12/11 14:55:55 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_signal.h"

t_error_code	mini_signal_set_heredoc(void)
{
	if (SIG_ERR == signal(SIGINT, SIG_DFL))
		return (SIGNAL_ERROR);
	if (SIG_ERR == signal(SIGQUIT, SIG_IGN))
		return (SIGNAL_ERROR);
	return (SUCCESS);
}
