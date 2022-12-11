/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:55:10 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/04 15:21:09 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

char	reader_is_del(char c, char del)
{
	if (SPACE_CHAR != del)
		return (c == del);
	return (reader_is_space(c));
}
