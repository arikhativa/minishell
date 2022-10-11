/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/11 14:12:07 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_error_code mode_file()
{
	return (SUCCESS);
	// open file
	// give reader the fd
	// close fd
}

t_error_code mode_stdin(char **envp)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			*bad_str;

	err = shell_op_create(&sp);
	if (SUCCESS != err)
		return (err);
	sp->envp = envp;
	sp->run = TRUE;
	while (sp->run)
	{
		// TODO reader should handle open pipe then FALSE it
		err = reader(&(sp->input));
		if (SUCCESS != err)
			return (err);
		if (NULL == sp->input)
			return (SUCCESS);
		err = laxer_create_token_list(sp);
		if (SUCCESS != err)
			return (err);
		err = parser_check_tokens(sp, &bad_str);
		if (SUCCESS != err)
		{
			if (SYNTAX_PIPE_STILL_OPEN == err)
			{
				sp->open_pipe = TRUE;
				continue;
			}
			if (SYNTAX_ERROR == err)
			{
				error_code_print(err, bad_str);
				return (err);
			}
			return (err);
		}
		err = commander_create_cmds(sp);
		if (SUCCESS != err)
			return (err);
		err = executer_run_all_cmds(sp);
		if (SUCCESS != err)
			return (err);
		cleaner_round_clean(sp);
	}
	shell_op_destroy(&sp);
	return (err);
}

int	main(int argc, char **argv, char **envp)
{
	t_error_code	err;

	if (mode_is_file_input(argc))
		err = mode_file(argv, envp);
	else
		err = mode_stdin(envp);
	return (err);
}
