/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/26 14:11:30 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// TODO SYNTAX_ERROR create error_code handler -- NO printf
static	t_error_code	handle_input(t_shell_op *sp, t_read_input read_func)
{
	t_error_code	err;

	err = read_func(&(sp->input));
	if (SUCCESS != err)
		return (err);
	if (NULL == sp->input)
		return (EOF_SUCCESS);
	err = laxer_create_token_list(sp);
	if (SUCCESS != err)
		return (err);
	err = parser_check_tokens(sp);
	return (err);
}

static	t_error_code	handle_valid_input(t_shell_op *sp)
{
	t_error_code	err;

	err = commander_create_cmds(sp);
	if (SUCCESS != err)
		return (err);
	err = executer_run_all_cmds(sp);
	if (SUCCESS != err)
		return (err);
	cleaner_round_clean(sp);
	return (SUCCESS);
}

static	t_error_code	internal_loop(t_shell_op *sp, t_read_input read_func)
{
	t_error_code	err;

	err = SUCCESS;
	while (sp->run && SUCCESS == err)
	{
		err = handle_input(sp, read_func);
		if (EOF_SUCCESS == err)
			return (SUCCESS);
		if (SYNTAX_PIPE_STILL_OPEN == err)
		{
			sp->open_pipe = TRUE;
			continue ;
		}
		if (SYNTAX_ERROR == err)
		{
			err = SUCCESS;
			continue ;
		}
		if (SUCCESS == err)
			err = handle_valid_input(sp);
	}
	return (SUCCESS);
}

// TODO reader should handle open pipe then FALSE it
static t_error_code	internal_flow(char **envp, t_read_input read_func)
{
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, envp);
	if (SUCCESS != err)
		return (err);
	sp->run = TRUE;
	env_inc_shlvl(&(sp->envp));
	err = internal_loop(sp, read_func);
	shell_op_destroy(&sp);
	return (err);
}

int	main(int argc, char **argv, char **envp)
{
	t_error_code	err;

	(void)argv;
	err = mini_signal_disable();
	if (SUCCESS != err)
		return (err);
	if (1 > argc)
	{
		printf("Can't Handle files\n");
		return (ERROR);
	}
	else
	{
		err = mini_signal_interactive_mode();
		if (SUCCESS != err)
			return (err);
		err = internal_flow(envp, reader_get_tab);
	}
	return (err);
}
