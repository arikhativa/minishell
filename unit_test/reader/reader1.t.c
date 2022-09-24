/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader1.t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/12 10:06:28 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "reader.h"
#include <fcntl.h>

static void	assert_tab(char **tab)
{
	CU_ASSERT_STRING_EQUAL(tab[0], "Alvaro");
	CU_ASSERT_STRING_EQUAL(tab[1], "Lopez");
	CU_ASSERT_STRING_EQUAL(tab[2], "<");
	CU_ASSERT_STRING_EQUAL(tab[3], "Gomez");
	CU_ASSERT_STRING_EQUAL(tab[4], ">>");
	CU_ASSERT_STRING_EQUAL(tab[5], "and");
	CU_ASSERT_STRING_EQUAL(tab[6], "|");
	CU_ASSERT_STRING_EQUAL(tab[7], "Yoa");
	CU_ASSERT_STRING_EQUAL(tab[8], ">>");
	CU_ASSERT_STRING_EQUAL(tab[9], "v");
	CU_ASSERT_STRING_EQUAL(tab[10], "|");
}

void	test_reader(void)
{
	char			**tab;
	t_error_code	err;

	err = tab_create(&tab, 2);
	CU_ASSERT(err == SUCCESS);
	tab_deep_destroy(&tab);
	err = reader_split_by_token("Alvaro Lopez <Gomez>> and | Yoa>>v| ", &tab);
	CU_ASSERT(err == SUCCESS);
	assert_tab(tab);
	tab_deep_destroy(&tab);
	err = reader_split_by_token("Hola que tal!|!", &tab);
	CU_ASSERT(err == SUCCESS);
	CU_ASSERT_STRING_EQUAL(tab[0], "Hola");
	CU_ASSERT_STRING_EQUAL(tab[1], "que");
	CU_ASSERT_STRING_EQUAL(tab[2], "tal!");
	CU_ASSERT_STRING_EQUAL(tab[3], "|");
	CU_ASSERT_STRING_EQUAL(tab[4], "!");
	tab_deep_destroy(&tab);
}
