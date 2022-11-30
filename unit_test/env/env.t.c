/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/22 23:58:01 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "env.h"
#include "tab.h"
#include "shell_op.h"

void	test_env(void)
{
	t_shell_op	sp;
	char		*tmp;

	env_initenv(&sp.envp, 0);
	CU_ASSERT(env_setvar(&sp.envp, "KEY_0", "VALUE 0") == SUCCESS);
	CU_ASSERT(env_setvar(&sp.envp, "KEY_1", "VALUE 1") == SUCCESS);
	CU_ASSERT(env_setvar(&sp.envp, "KEY_2", "VALUE 2") == SUCCESS);
	CU_ASSERT(env_setvar(&sp.envp, "KEY_3", "VALUE 3") == SUCCESS);
	CU_ASSERT(env_setvar(&sp.envp, "KEY_4", "VALUE 4") == SUCCESS);
	env_unsetvar(sp.envp, "KEY_4");
	env_unsetvar(sp.envp, "KEY_-1");
	CU_ASSERT(env_setvar(&sp.envp, "KEY_5", "VALUE 5") == SUCCESS);
	CU_ASSERT(env_setvar(&sp.envp, "KEY_5", "VALUE 5.2") == SUCCESS);
	CU_ASSERT(env_setvar(&sp.envp, "KEY_6", "VALUE 6") == SUCCESS);
	env_unsetvar(sp.envp, "KEY_6");
	CU_ASSERT(env_setvar(&sp.envp, "KEY_7", "VALUE 7") == SUCCESS);
	CU_ASSERT(env_setvar(&sp.envp, "KEY_8", "VALUE 8") == SUCCESS);
	CU_ASSERT(env_setvar(&sp.envp, "KEY_9", "VALUE 9") == SUCCESS);
	env_unsetvar(sp.envp, "KEY_2");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 2), "KEY_9=VALUE 9");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 6), "KEY_8=VALUE 8");
	tmp = env_getvar(sp.envp, "KEY_1");
	CU_ASSERT_STRING_EQUAL(tmp, "VALUE 1");
	env_destroy(&(sp.envp));
}
