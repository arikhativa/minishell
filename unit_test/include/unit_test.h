/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:56:02 by yoav              #+#    #+#             */
/*   Updated: 2022/12/14 16:29:59 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include <stdio.h>
# include <string.h>
# include "CUnit/Basic.h"

# include "env.h"
# include "error_code.h"

# define TEST_RES "unit_test_tmp.txt"
# define TEST_FILE "test_file"
# define TEST_FILE2 "test_file2"

extern char			**g_envp;

extern CU_TestInfo	g_builtin_stream_tests[];
extern CU_TestInfo	g_pipe_pair_tests[];
extern CU_TestInfo	g_pipe_tests[];
extern CU_TestInfo	g_gnl_tests[];
extern CU_TestInfo	g_commander_tests[];
extern CU_TestInfo	g_executer_tests[];
extern CU_TestInfo	g_parser_tests[];
extern CU_TestInfo	g_cmd_list_tests[];
extern CU_TestInfo	g_laxer_tests[];
extern CU_TestInfo	g_shell_op_tests[];
extern CU_TestInfo	g_tab_tests[];
extern CU_TestInfo	g_redirecter_tests[];
extern CU_TestInfo	g_reader_tests[];
extern CU_TestInfo	g_env_tests[];
extern CU_TestInfo	g_expander_tests[];
extern CU_TestInfo	g_token_list_tests[];
extern CU_TestInfo	g_token_tests[];
extern CU_TestInfo	g_dll_tests[];
extern CU_SuiteInfo	g_suites[];

// main
int		init_suite(void);
int		clean_suite(void);

// builtins_stream
void	test_builtin_out_stream(void);

// parser
void	test_parser_redirect_error(void);
void	test_parser_token_check(void);
void	test_parser_bad_first_tok(void);
void	test_parser_pipe_limit(void);

// commander
void	test_commander(void);
void	test_path_var_search(void);
void	test_commander_redirect(void);

// cmd_list
void	test_cmd_list_create_destroy(void);

// arg_list
void	test_arg_list_create_destroy(void);

// pipe_pair
void	test_pipe_pair_create_destroy(void);
void	test_pipe_pair_open_close(void);

// pipe
void	test_pipe_create_destroy(void);
void	test_pipe_open_close(void);

// laxer
void	test_laxer_create_destroy(void);
void	test_laxer_check_all_tokens(void);

// test_redirecter
void	test_redirecter_multi(void);
void	test_redirecter_append(void);
void	test_redirecter_out(void);
void	test_redirecter_no_cmd(void);
void	test_redirecter_in(void);

// executer
void	test_multi_cmd_exec(void);
void	test_return_value(void);

// shell_op
void	test_shell_op_create_destroy_empty(void);
void	test_shell_op_create_destroy_with_tab(void);
void	test_shell_op_create_destroy_with_token_list(void);

// tab
void	test_tab_add(void);
void	test_tab_create_destroy(void);

// reader
void	test_reader(void);
void	test_reader_fake_stdin(void);

//expander
void	test_expander(void);

// env
void	test_env(void);

// gnl
void	test_gnl(void);

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
