/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/20 17:41:29 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "reader.h"
#include "cleaner.h"
#include <fcntl.h>

void	internal_reader_fake_stdin2(t_shell_op *sp)
{
	char	**tab;

	reader_get_tab(sp);
	tab = sp->input;
	CU_ASSERT_STRING_EQUAL(tab[0], "cat");
	CU_ASSERT_STRING_EQUAL(tab[1], "other_file");
	CU_ASSERT_STRING_EQUAL(tab[2], "|");
	CU_ASSERT_STRING_EQUAL(tab[3], "grep");
	CU_ASSERT_STRING_EQUAL(tab[4], "-a");
	CU_ASSERT_STRING_EQUAL(tab[5], "|");
	CU_ASSERT_STRING_EQUAL(tab[6], "echo");
	tab_deep_destroy(&(sp->input));
	printf("\n");
	reader_get_tab(sp);
	tab_deep_destroy(&(sp->input));
	printf("\n");
	reader_get_tab(sp);
	tab = sp->input;
	CU_ASSERT_STRING_EQUAL(tab[0], "opened");
	CU_ASSERT_STRING_EQUAL(tab[1], "quote");
	CU_ASSERT_STRING_EQUAL(tab[2], "\'textmore textpipes|red<>now \"close\'");
	tab_deep_destroy(&(sp->input));
	printf("\n");
}

void	internal_reader_fake_stdin1(t_shell_op *sp)
{
	char	**tab;

	reader_get_tab(sp);
	tab_deep_destroy(&(sp->input));
	printf("\n");
	reader_get_tab(sp);
	tab = sp->input;
	CU_ASSERT_STRING_EQUAL(tab[0], "cat");
	CU_ASSERT_STRING_EQUAL(tab[1], "file");
	tab_deep_destroy(&(sp->input));
	printf("\n");
	reader_get_tab(sp);
	tab_deep_destroy(&(sp->input));
	printf("\n");
}

void	internal_reader_fake_stdin0(t_shell_op *sp)
{
	char	**tab;

	reader_get_tab(sp);
	tab = sp->input;
	CU_ASSERT_STRING_EQUAL(tab[0], "echo");
	CU_ASSERT_STRING_EQUAL(tab[1], "Hello");
	CU_ASSERT_STRING_EQUAL(tab[2], "wasup");
	tab_deep_destroy(&(sp->input));
	printf("\n");
}

void	test_reader_fake_stdin(void)
{
	int				fd;
	t_error_code	err;
	t_shell_op		*sp;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	fd = open("./unit_test/resources/simple_cmd.sh", O_RDONLY);
	close(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	internal_reader_fake_stdin0(sp);
	internal_reader_fake_stdin1(sp);
	internal_reader_fake_stdin2(sp);
	shell_op_destroy(&sp);
}
