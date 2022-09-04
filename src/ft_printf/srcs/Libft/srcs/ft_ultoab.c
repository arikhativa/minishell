/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:17:32 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/24 05:25:49 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/libft.h"

static int	base_digits(unsigned long n, int bs_cnt, char *base)
{
	int				aux;
	unsigned long	b;

	b = (unsigned long)bs_cnt;
	aux = 0;
	if (n >= b)
		aux = base_digits(n / b, b, base) + 1;
	return (aux);
}

/*
** Function: check_repeated
** ---------------------
** One of the functions which validates the bases,
** checking wheter any digit is repeated
**
** char	*tab:	digits of base in a string list
** int	cnt:	cnt the numbers of digits in the base
**
** returns:		1 if valid 0 if not
*/

static int	check_repeated(char *tab, int cnt)
{
	int	aux;

	while (cnt > 0)
	{
		aux = cnt - 1;
		while (aux >= 0)
		{
			if (*(tab + cnt) == *(tab + aux))
				return (0);
			aux--;
		}
		cnt--;
	}
	return (1);
}

/*
** Function: to_base
** ---------------------
** Convert decimal nbr to base base
**
** size_t	nbr:	Decimal number to convert
** char *	base:	Base to convert to
**
** returns:         strings with decimal number in base base
*/

static char	*to_base(unsigned long n, int bs_cnt, char *base)
{
	unsigned long	num;
	char			*str;
	int				len;
	int				aux;
	int				mod;

	aux = 0;
	num = n;
	len = base_digits(num, bs_cnt, base) + 1;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	*(str + len) = '\0';
	while (aux < len)
	{
		mod = n % 16;
		n = n / 16;
		*(str + (len - 1 - aux)) = *(base + mod);
		aux++;
	}
	return (str);
}

/*
** Function: ft_itoab
** ---------------------
** Convert decimal nbr to base base
**
** size_t	nbr:	Decimal number to convert
** char *	base:	Base to convert to
**
** returns:         strings with decimal number in base base
*/

char	*ft_ultoab(unsigned long n, char *base)
{
	int		base_cnt;
	int		valid;
	char	*str;

	str = NULL;
	valid = 1;
	base_cnt = 0;
	while (*(base + base_cnt) != '\0')
	{
		if (*(base + base_cnt) == 43 || *(base + base_cnt) == 45)
			valid = !valid;
		base_cnt++;
	}
	if (base_cnt > 1 && valid && check_repeated(base, base_cnt))
		str = to_base(n, base_cnt, base);
	return (str);
}
