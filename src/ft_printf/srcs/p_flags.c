/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:22:53 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/08 02:01:16 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft/includes/libft.h"

/*
** Function: apply_p_flags
** ------------------------
**
** const char *pos: input string
** t_info *si:      info structure
** t_flags *sf:     flag structure
** int  n:          num to print
*/

void	p_flags(t_info *si, t_flags *sf, char *str)
{
	int	ls;
	int	lt;

	sf->width -= 2;
	sf->width += (*str == 48 && !sf->prc);
	lt = ft_strlen(str);
	if (sf->prc > (int)ft_strlen(str) - (*str == '-'))
		lt = sf->prc + (*str == '-');
	ls = lt;
	if (lt == 0 || lt == -1)
		ls = ft_strlen(str);
	lt = (sf->width > lt) * sf->width + !(sf->width > lt) * lt;
	if ((sf->zero && sf->prc == -1))
			ls = lt;
	space(!(sf->neg) * (lt - ls), 0, si);
	write(1, "-", (*str == '-'));
	write(1, "0x", 2);
	space(ls - ft_strlen(str), 1, si);
	if (!(!sf->prc && *str == 48))
		ft_putstr_fd(str + (1 * (*str == '-')), 1);
	space((sf->neg) * (lt - ls), 0, si);
	si->t += ft_strlen(str) + 2 - (*str == 48 && !sf->ptr);
	if (str)
		free(str);
}

void	apply_perc(t_info *si, t_flags *sf)
{
	if (!sf->neg)
		space(sf->width - 1, sf->zero, si);
	write(1, "%%", 1);
	if (sf->neg)
		space(sf->width - 1, 0, si);
	si->t++;
}
