/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:51:03 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 15:46:32 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft/includes/libft.h"

/*
** Function: ft_printf
** ----------------------------
** Original printf copy
**
** const char *in:  input string to be formated and printed
** ...              length-undetermined list of arguments to print with format
**
** returns:         number of chars printed
*/

int	ft_printf(const char *in, ...)
{
	t_flags	sf;
	t_info	si;

	init_info_struct(&si);
	va_start(si.ap, in);
	while (*(in + si.i))
	{
		if (*(in + si.i) == 37)
		{
			if (*(in + ++si.i) == 37)
				write(1, "%", 1);
			else
				process_in(in + --si.i + 1, &si, &sf);
		}
		else
		{
			si.t++;
			write(1, in + si.i, 1);
		}
		if (*(in + si.i) != 0)
			si.i++;
	}
	va_end(si.ap);
	return (si.t);
}
