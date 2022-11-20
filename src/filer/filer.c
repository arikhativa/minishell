/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:29:25 by yoav              #+#    #+#             */
/*   Updated: 2022/11/03 10:50:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filer.h"

t_bool	filer_is_executable(char *path)
{
	struct stat	s;
	int			stt;

	stt = stat(path, &s);
	if (SUCCESS == stt)
		return (S_ISREG(s.st_mode) && (s.st_mode & S_IXUSR));
	return (FALSE);
}

t_bool	filer_is_dir(char *path)
{
	struct stat	s;
	int			stt;

	stt = stat(path, &s);
	if (SUCCESS == stt)
		return (S_ISDIR(s.st_mode));
	return (FALSE);
}

t_bool	filer_is_file(char *path)
{
	struct stat	s;
	int			stt;

	stt = stat(path, &s);
	if (SUCCESS == stt)
		return (S_ISREG(s.st_mode));
	return (FALSE);
}

t_bool	filer_is_exec_prem(char *path)
{
	struct stat	s;
	int			stt;

	stt = stat(path, &s);
	if (SUCCESS == stt)
		return (!!(s.st_mode & S_IXUSR));
	return (FALSE);
}
