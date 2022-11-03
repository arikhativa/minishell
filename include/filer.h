/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:35:56 by yoav              #+#    #+#             */
/*   Updated: 2022/11/03 10:50:31 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILER_H
# define FILER_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# include "error_code.h"
# include "macro.h"

t_bool	filer_is_executable(char *path);
t_bool	filer_is_dir(char *path);
t_bool	filer_is_file(char *path);
t_bool	filer_is_exec_prem(char *path);

#endif
