/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:56:45 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/07 01:20:36 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft/includes/libft.h"

static void	adjust_flags(t_flags *sf)
{
	if (sf->width < 0)
	{
		sf->width = -sf->width;
		sf->neg = 1;
	}
	if (sf->prc < -1)
		sf->prc = -1;
	if (sf->neg && sf->zero)
		sf->zero = 0;
}

/*
** Function: check_flag_struct
** ----------------------------
** Once moddifier is found fills struct with input flags
**
** const char *pos: input string
** t_info *si:      info structure
** t_flags *sf:     flag structure
*/

void	check_flag_struct(const char *pos, t_info *si, t_flags *sf)
{
	int	i;

	i = -1;
	while (ft_strchr(si->flags, *(pos + ++i)))
	{
		if (!(sf->width) && sf->prc == -1 && *(pos + i) == 42)
			sf->width = va_arg(si->ap, int);
		else if (sf->prc == -1 && *(pos + i) == '.' && *(pos + i + 1) == 42)
			sf->prc = va_arg(si->ap, int);
		if ((!(sf->width) && *(pos + i) > 48 && *(pos + i) <= 57
				&& sf->prc == -1))
			sf->width = ft_atoi(pos + i);
		else if (*(pos + i) == '0' && !(sf->width))
			sf->zero = 1;
		else if (sf->prc == -1 && *(pos + i) == '.' && (*(pos + i + 1) != '-'))
		{
			sf->prc = -2;
			if (*(pos + i + 1) >= 48 && *(pos + i) <= 57)
				sf->prc = ft_atoi(pos + i + 1);
		}
		if (*(pos + i) == '-')
			sf->neg = 1;
	}
	adjust_flags(sf);
	si->i = si->i + 1 + (i * (i != 0));
}

/*
** Function: init_flag_struct
** ---------------------------
** Set flag struct content to 0
**
** t_flags *sf:     flag structure
*/

void	init_flags_struct(t_flags *sf)
{
	sf->neg = 0;
	sf->prc = -1;
	sf->ptr = 0;
	sf->width = 0;
	sf->zero = 0;
}

/*
** Function: init_info_struct
** ---------------------------
** Set info struct content to 0
**
** t_info *si: info structure
*/

void	init_info_struct(t_info *si)
{
	si->i = 0;
	si->t = 0;
	si->flags = "-0.*123456789 +#";
	si->mods = "cspdiuxX%%";
}
