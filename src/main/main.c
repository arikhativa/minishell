/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/06 10:59:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;
	t_shell_op	*sp;
	int		file_fd;
	char	*line;
	int	i = 0;

	if (1 < argc)
	{
		file_fd = open(argv[1], O_RDONLY);
		line = get_next_line(file_fd);
		shell_op_create(&sp);
		shell_op_set_input(sp, ft_split(line, ' '));
		laxer_create_token_list(sp);
		parser_check_tokens(sp, &line);
		// replace with "commander"
		cmd_create(&cmd);
		while (sp->input[i])
		{
			cmd_add_arg(cmd, sp->input[i]);
			++i;
		}
		cmd->env = envp;
		cmd_list_create(&(sp->cmd_list));
		cmd_list_add_cmd(sp->cmd_list, cmd);
		executer_run_cmd_list(sp);
		
		// free
		while (line)
		{
			free(line);
			line = get_next_line(file_fd);
		}
		close(file_fd);
	}
	return (0);
}
