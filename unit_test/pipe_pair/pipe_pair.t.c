/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pair.t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:21:30 by yoav              #+#    #+#             */
/*   Updated: 2022/11/02 12:21:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "unit_test.h"
#include "macro.h"
#include "pipe_pair.h"

void	test_pipe_pair_create_destroy(void)
{
	t_error_code	err;
	t_pipe_pair		*pp;

	err = pipe_pair_create(&pp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	pipe_pair_destroy(&pp);
	CU_ASSERT_PTR_NULL(pp);
}

void	test_pipe_pair_open_close(void)
{
	t_error_code	err;
	t_pipe_pair		*pp;
	int				pipes[2];

	err = pipe_pair_create(&pp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = pipe(pipes);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	pipe_pair_init_in(pp, pipes[PIPE_READ]);
	pipe_pair_init_out(pp, pipes[PIPE_WRITE]);
	err = pipe_pair_close(pp);
	CU_ASSERT_EQUAL(SUCCESS, err);
	err = pipe_pair_close(pp);
	CU_ASSERT_EQUAL(SUCCESS, err);
	pipe_pair_destroy(&pp);
	CU_ASSERT_PTR_NULL(pp);
}
