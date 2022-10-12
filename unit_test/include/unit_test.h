/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:56:02 by yoav              #+#    #+#             */
/*   Updated: 2022/09/25 16:32:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include <stdio.h>
# include <string.h>
# include "CUnit/Basic.h"

# include "error_code.h"

# define TEST_RES "unit_test_tmp.txt"

extern CU_TestInfo	g_parser_tests[];
extern CU_TestInfo	g_cmd_list_tests[];
extern CU_TestInfo	g_arg_list_tests[];
extern CU_TestInfo	g_laxer_tests[];
extern CU_TestInfo	g_shell_op_tests[];
extern CU_TestInfo	g_tab_tests[];
extern CU_TestInfo	g_reader_tests[];
extern CU_TestInfo	g_token_list_tests[];
extern CU_TestInfo	g_token_tests[];
extern CU_TestInfo	g_dll_tests[];
extern CU_SuiteInfo	g_suites[];

// main
int		init_suite(void);
int		clean_suite(void);

// parser
void	test_parser_open_pipe(void);
void	test_parser_semi_redirect_error(void);
void	test_parser_token_check(void);
void	test_parser_bad_first_tok(void);

// cmd_list
void	test_cmd_list_create_destroy(void);

// arg_list
void	test_arg_list_create_destroy(void);

// laxer
void	test_laxer_create_destroy(void);
void	test_laxer_check_all_tokens(void);

// shell_op
void	test_shell_op_create_destroy_empty(void);
void	test_shell_op_create_destroy_with_tab(void);
void	test_shell_op_create_destroy_with_token_list(void);

// tab
void	test_tab_create_destroy(void);

// reader
void	test_reader(void);
void	test_reader_fake_stdin(void);

// token
void	test_token_create_destroy(void);

// token list
void	test_tok_lst_create_destroy(void);

// dll tests
void	test_dll_add_before(void);
void	test_dll_swap_value(void);
void	test_dll_create_and_destroy_elem(void);
void	test_dll_clear_list(void);
void	test_dll_add_last(void);
void	test_dll_add_after(void);
void	test_dll_get_last_elem(void);
void	test_dll_remove_first_elem(void);
void	test_dll_remove_last_elem(void);
void	test_dll_remove_elem(void);

#endif
