/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:23:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/06 16:51:38 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft/includes/libft.h"
#include <stdio.h>

/*
** Function: apply_s_flags
** ------------------------
**
** const char *pos: input string
** t_info *si:      info structure
** t_flags *sf:     flag structure
** char *str:       str to print
*/

void	s_flags(t_info *si, t_flags *sf, char *str)
{
	int	final_s_len;
	int	final_t_len;

	if (str == NULL)
		str = "(null)";
	final_s_len = (int)ft_strlen(str);
	if (sf->prc != -1 && sf->prc < final_s_len)
			final_s_len = sf->prc;
	final_t_len = final_s_len;
	if (sf->width > final_s_len)
		final_t_len = sf->width;
	if (sf->neg)
		write(1, str, final_s_len);
	space(final_t_len - final_s_len, sf->zero, si);
	if (!sf->neg)
		write(1, str, final_s_len);
	si->t += final_s_len;
}
