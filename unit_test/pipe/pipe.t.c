/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:48:43 by yoav              #+#    #+#             */
/*   Updated: 2022/10/31 10:07:03 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "unit_test.h"
#include "macro.h"
#include "pipe.h"

void	test_pipe_create_destroy(void)
{
	t_error_code	err;
	t_pipe			*p;

	err = pipe_create(&p);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	pipe_destroy(&p);
	CU_ASSERT_PTR_NULL(p);
}

void	test_pipe_open_close(void)
{
	t_error_code	err;
	t_pipe			*p;
	int				pipes[2];

	err = pipe_create(&p);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = pipe(pipes);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	pipe_init(p, PIPE_IN, pipes[PIPE_INDEX_READ]);
	err = pipe_close(p);
	CU_ASSERT_EQUAL(SUCCESS, err);
	err = pipe_close(p);
	CU_ASSERT_EQUAL(SUCCESS, err);
	pipe_destroy(&p);
	CU_ASSERT_PTR_NULL(p);
}
