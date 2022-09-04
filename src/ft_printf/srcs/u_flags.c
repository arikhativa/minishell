/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:20:11 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/07 19:29:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft/includes/libft.h"

/*
** Function: apply_u_flags
** ------------------------
**
** const char *pos: input string
** t_info *si:      info structure
** t_flags *sf:     flag structure
** int  n:          num to print
*/

void	u_flags(t_info *si, t_flags *sf, char *str)
{
	int	ls;
	int	lt;

	lt = ft_strlen(str);
	if (sf->prc > (int)ft_strlen(str) - (*str == '-'))
		lt = sf->prc + (*str == '-');
	ls = lt;
	if (lt == 0 || lt == -1)
		ls = ft_strlen(str);
	if (sf->width > lt)
		lt = sf->width;
	if ((sf->zero && sf->prc == -1))
		ls = lt;
	space((!sf->neg) * (lt - ls), 0, si);
	write(1, "-", (*str == '-'));
	space(ls - ft_strlen(str), 1, si);
	if (!sf->prc && *str == 48)
		*str = ' ';
	if (!sf->prc && *str == 32 && sf->width == 0)
		*str = 0;
	ft_putstr_fd(str + (1 * (*str == '-')), 1);
	space((sf->neg) * (lt - ls), 0, si);
	si->t += ft_strlen(str);
	if (str)
		free(str);
}
