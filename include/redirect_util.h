/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:01:33 by yoav              #+#    #+#             */
/*   Updated: 2022/10/26 12:27:04 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_UTIL_H
# define REDIRECT_UTIL_H

# include "libft.h"
# include "macro.h"

t_bool	is_rr(char *s);
t_bool	is_rl(char *s);
t_bool	is_drr(char *s);
t_bool	is_drl(char *s);
t_bool	is_redirect(char *s);

#endif
