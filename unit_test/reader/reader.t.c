/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/11 13:43:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "unit_test_util.h"
#include "unit_test.h"
#include "reader.h"

void	test_reader(void)
{
	char 			**tab;
	t_error_code	err;

	CU_ASSERT(quote_is_closed("\'\'"));
	CU_ASSERT(!quote_is_closed("\'"));
	CU_ASSERT(quote_is_closed("\"\""));
	CU_ASSERT(!quote_is_closed("\""));

	CU_ASSERT(cnt_words("Alvaro Lopez <Gomez>> and|Yoav|") == 9);
	CU_ASSERT(cnt_words("|<|") == 3);
	CU_ASSERT(cnt_words("|<<<<|") == 3);

	err = tab_create(&tab, 9);
	CU_ASSERT(err == SUCCESS);
	err = allocate_words("Alvaro Lopez <Gomez>> and|Yoav|", &tab, 9);
	CU_ASSERT(err == SUCCESS);
	tab_deep_destroy(&tab);
}

void	test_reader_fake_stdin(void)
{
	int		fd;
	char	*line;

	fd = open("./unit_test/resources/simple_cmd.sh", O_RDONLY);
	close(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	line = readline(IGNORE_PROMPT);
	CU_ASSERT_PTR_NOT_NULL_FATAL(line);
	printf("'%s'\n", line);
}
