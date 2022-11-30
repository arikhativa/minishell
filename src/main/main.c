/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/17 01:43:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "token_list.h"

static t_error_code	file_logic(char **argv, char **envp)
{
	t_error_code	err;
	int				fd;

	fd = open(*(argv + 1), O_RDONLY);
	if (fd < 0)
		return (fd);
	err = dup_wrapper(fd, STDIN_FILENO);
	if (SUCCESS != err)
		return (err);
	err = internal_flow(NULL, envp, reader_get_tab_from_file);
	close(fd);
	return (err);
}

// TODO error class
int	main(int argc, char **argv, char **envp)
{
	t_error_code	err;

	err = mini_signal_disable();
	if (SUCCESS != err)
		return (err);
	if (mode_mngr_is_cli(argc, argv))
		return (internal_flow(argv[2], envp, reader_get_tab_from_cli));
	if (mode_mngr_is_file(argc))
		return (file_logic(argv, envp));
	if (mode_mngr_is_stdin())
		return (internal_flow(NULL, envp, reader_get_tab_from_file));
	err = mini_signal_interactive_mode();
	if (SUCCESS != err)
		return (err);
	return (internal_flow(NULL, envp, reader_get_tab));
}
