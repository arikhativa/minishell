/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:49:12 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 09:55:21 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "token.h"

void	test_token_create_destroy(void)
{
	t_error_code	err;
	t_token			*t;
	char			*str;

	str = "string";
	err = token_create(&t, str, WORD);
	CU_ASSERT_EQUAL(err, SUCCESS);
	CU_ASSERT_PTR_NOT_NULL(t);
	CU_ASSERT_EQUAL(t->type, WORD);
	CU_ASSERT_EQUAL(t->value, str);
	token_destroy(&t);
	CU_ASSERT_PTR_NULL(t);
}
