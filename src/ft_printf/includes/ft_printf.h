/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:49:23 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/07 00:57:41 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int			neg;
	int			width;
	int			zero;
	int			prc;
	int			ptr;
}				t_flags;
typedef struct s_info
{
	int			i;
	int			t;
	char		*flags;
	char		*mods;
	va_list		ap;
}				t_info;
int				ft_printf(const char *in, ...);
void			process_in(const char *pos, t_info *si, t_flags *sf);
char			mod_finder(const char *pos, t_info *si);
void			check_flag_struct(const char *pos, t_info *si, t_flags *sf);
void			init_info_struct(t_info *si);
void			init_flags_struct(t_flags *sf);

void			c_flags(t_info *si, t_flags *sf, int c);
void			s_flags(t_info *si, t_flags *sf, char *str);
void			d_flags(t_info *si, t_flags *sf, char *str);
void			u_flags(t_info *si, t_flags *sf, char *str);
void			p_flags(t_info *si, t_flags *sf, char *str);
void			x_flags(t_info *si, t_flags *sf, char *str);
void			apply_perc(t_info *si, t_flags *sf);

void			space(int num, int zero, t_info *si);

#endif
