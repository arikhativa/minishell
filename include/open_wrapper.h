/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wrapper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:15:25 by yoav              #+#    #+#             */
/*   Updated: 2023/09/23 17:14:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_WRAPPER_H
# define OPEN_WRAPPER_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "redirect.h"
# include "error_code.h"

# define FILE_PERM		0000664

t_error_code	open_file(t_redirect *r);

#endif
