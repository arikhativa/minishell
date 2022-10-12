/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_util.t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:57:29 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 12:24:04 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"

static char	*copy_str(char *s)
{
	char	*ret;

	ret = ft_strdup(s);
	CU_ASSERT_PTR_NOT_NULL_FATAL(ret);
	return (ret);
}

char	**util_create_tab(int size, ...)
{
	va_list			list;
	char			**tab;
	char			*s;
	int				i;

	va_start(list, size);
	if (SUCCESS != tab_create(&tab, size))
		CU_ASSERT_FATAL(CU_FALSE);
	i = 0;
	while (i < size)
	{
		s = va_arg(list, char *);
		tab[i] = copy_str(s);
		++i;
	}
	va_end(list);
	return (tab);
}

void	util_check_file_and_remove(char *filename)
{
	if (SUCCESS == access(filename, F_OK))
	{
		if (SUCCESS != remove(filename))
			CU_FAIL("file was not deleted");
	}
	else
		CU_FAIL("file was not created");
}
