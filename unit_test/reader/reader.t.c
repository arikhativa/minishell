/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/12 10:05:23 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "reader.h"
#include <fcntl.h>

void	internal_reader_fake_stdin2(void)
{
	char	**tab;

	reader_get_tab(&tab);
	CU_ASSERT_STRING_EQUAL(tab[0], "cat");
	CU_ASSERT_STRING_EQUAL(tab[1], "other_file");
	CU_ASSERT_STRING_EQUAL(tab[2], "|");
	CU_ASSERT_STRING_EQUAL(tab[3], "grep");
	CU_ASSERT_STRING_EQUAL(tab[4], "-a");
	CU_ASSERT_STRING_EQUAL(tab[5], "|");
	CU_ASSERT_STRING_EQUAL(tab[6], "echo");
	tab_deep_destroy(&tab);
	printf("\n");
	reader_get_tab(&tab);
	tab_deep_destroy(&tab);
	printf("\n");
	reader_get_tab(&tab);
	CU_ASSERT_STRING_EQUAL(tab[0], "opened");
	CU_ASSERT_STRING_EQUAL(tab[1], "quote");
	CU_ASSERT_STRING_EQUAL(tab[2], "\'textmore textpipes|red<>now \"close\'");
	tab_deep_destroy(&tab);
	printf("\n");
}

void	internal_reader_fake_stdin1(void)
{
	char	**tab;

	reader_get_tab(&tab);
	tab_deep_destroy(&tab);
	printf("\n");
	reader_get_tab(&tab);
	CU_ASSERT_STRING_EQUAL(tab[0], "cat");
	CU_ASSERT_STRING_EQUAL(tab[1], "file");
	tab_deep_destroy(&tab);
	printf("\n");
	reader_get_tab(&tab);
	tab_deep_destroy(&tab);
	printf("\n");
}

void	internal_reader_fake_stdin0(void)
{
	char	**tab;

	reader_get_tab(&tab);
	CU_ASSERT_STRING_EQUAL(tab[0], "echo");
	CU_ASSERT_STRING_EQUAL(tab[1], "Hello");
	CU_ASSERT_STRING_EQUAL(tab[2], "wasup");
	tab_deep_destroy(&tab);
	printf("\n");
}

void	test_reader_fake_stdin(void)
{
	int		fd;

	fd = open("./unit_test/resources/simple_cmd.sh", O_RDONLY);
	close(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	internal_reader_fake_stdin0();
	internal_reader_fake_stdin1();
	internal_reader_fake_stdin2();
}
