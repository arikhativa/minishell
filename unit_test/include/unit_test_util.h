/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:20:37 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 12:24:39 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_UTIL_H
# define UNIT_TEST_UTIL_H

# include <stdarg.h>
# include <unistd.h>

# include "libft.h"
# include "tab.h"
# include "error_code.h"
# include "unit_test.h"

char	**util_create_tab(int size, ...);
void	util_check_file_and_remove(char *filename);

#endif
