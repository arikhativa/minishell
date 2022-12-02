/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_internal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/29 18:45:43 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "main.h"
#include "token_list.h"

// TODO SYNTAX_ERROR create error_code handler -- NO printf
t_error_code	handle_input(t_shell_op *sp, t_read_input read_func)
{
	t_error_code	err;

	err = read_func(sp);
	if (SUCCESS != err)
		return (err);
	if (NULL == sp->input)
		return (EOF_SUCCESS);
	if (!(**(sp->input)))
		return (NO_INPUT);
	err = laxer_create_token_list(sp);
	if (SUCCESS != err)
		return (err);
	err = expander_remove_all_quotes(sp);
	if (SUCCESS != err)
		return (err);
	err = parser_check_tokens(sp);
	return (err);
}

t_error_code	handle_valid_input(t_shell_op *sp)
{
	t_error_code	err;

	err = commander_create_cmds(sp);
	if (SUCCESS != err)
		return (err);
	err = redirecter_setup_files(sp);
	if (SUCCESS != err)
		return (err);
	err = piper_init_pipes(sp);
	if (SUCCESS != err)
		return (err);
	err = executer_run_all_cmds(sp);
	if (SUCCESS != err)
		return (err);
	cleaner_round_clean(sp);
	return (SUCCESS);
}

// TODO think of the printf()
t_error_code	internal_loop(t_shell_op *sp, t_read_input read_func)
{
	t_error_code	err;

	err = SUCCESS;
	while (sp->run && SUCCESS == err)
	{
		err = handle_input(sp, read_func);
		if (END_OF_TRANSMISSION == err)
		{
			printf("exit\n");
			return (SUCCESS);
		}
		if (EOF_SUCCESS == err)
			return (SUCCESS);
		if (SYNTAX_PIPE_STILL_OPEN == err)
			sp->open_pipe = TRUE;
		else if (SYNTAX_ERROR == err || NO_INPUT == err)
			err = SUCCESS;
		else if (SUCCESS == err)
			err = handle_valid_input(sp);
	}
	return (err);
}

// TODO reader should handle open pipe then FALSE it
t_error_code	internal_flow(char *cli_input, char **envp, \
	t_read_input read_func)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, envp);
	if (SUCCESS != err)
		return (err);
	sp->run = TRUE;
	env_inc_shlvl(&(sp->envp));
	if (cli_input)
		sp->cli_input = cli_input;
	err = internal_loop(sp, read_func);
	shell_op_destroy(&sp);
	return (err);
}
