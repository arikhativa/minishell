/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:48:43 by yoav              #+#    #+#             */
/*   Updated: 2022/10/19 15:51:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include "unit_test.h"
#include "libft.h"

#define GNL_TEST_FILE	"unit_test/resources/gnl_file"

void	test_gnl(void)
{
	int		fd;
	char	*line;

	fd = open(GNL_TEST_FILE, O_RDONLY);
	if (-1 == fd)
		CU_FAIL_FATAL();
	line = get_next_line(fd);
	CU_ASSERT_PTR_NOT_NULL_FATAL(line);
	CU_ASSERT_STRING_EQUAL(line, "text in file");
	free(line);
	line = get_next_line(fd);
	CU_ASSERT_PTR_NULL(line);
	close(fd);
}
