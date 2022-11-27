/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_mngr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/11/20 17:09:59 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mode_mngr.h"

t_bool	mode_mngr_is_cli(int argc, char **argv)
{
	return (argc >= 3 && !ft_strcmp(argv[1], C_FLAG_STR));
}

t_bool	mode_mngr_is_file(int argc)
{
	return (1 < argc);
}

t_bool	mode_mngr_is_stdin(void)
{
	return (!isatty(STDIN_FILENO));
}
