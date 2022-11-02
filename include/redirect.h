/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:46:44 by yoav              #+#    #+#             */
/*   Updated: 2022/10/27 10:27:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "error_code.h"
# include "macro.h"

typedef enum e_redirect_type
{
	NON = 0,
	IN = 1,
	OUT,
	APPEND,
}	t_redirect_type;

typedef struct s_redirect
{
	t_redirect_type	type;
	char			*path;
	int				fd;
}	t_redirect;

t_error_code	redirect_create(t_redirect **ret);
void			redirect_init(t_redirect *r, char *path, t_redirect_type t);
void			redirect_destroy(t_redirect **r);

#endif
