/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_qoute_logic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:05:08 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/02 17:37:45 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	update_stt(t_quote *stt, char c)
{
	if (IN_QUOTE == stt->single_quote)
	{
		if (SINGLE_QUOTE_CHAR == c)
			stt->single_quote = OUT_QUOTE;
		stt->in = FALSE;
		return ;
	}
	if (IN_QUOTE == stt->double_quote)
	{
		if (DOUBLE_QUOTE_CHAR == c)
			stt->double_quote = OUT_QUOTE;
		stt->in = TRUE;
		return ;
	}
	if (OUT_QUOTE == stt->double_quote && OUT_QUOTE == stt->single_quote)
	{
		if (DOUBLE_QUOTE_CHAR == c)
			stt->double_quote = IN_QUOTE;
		if (SINGLE_QUOTE_CHAR == c)
			stt->single_quote = IN_QUOTE;
	}
	stt->in = TRUE;
}
