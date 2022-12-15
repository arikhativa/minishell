/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_mngr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/12/15 13:25:41 by yrabby           ###   ########.fr       */
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

t_bool	mode_mngr_is_interactive(void)
{
	t_shell_op	*sp;

	sp = shell_op_get_sp(NULL);
	if (!sp)
		return (isatty(STDIN_FILENO));
	return (sp->is_interactive);
}
