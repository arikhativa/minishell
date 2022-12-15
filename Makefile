# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/12/15 15:10:15 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 					= minishell

#---------- HEAD ----------
HEAD_DIR 				= include
HEAD_NAME 				= \
	dll.h \
	filer.h \
	env_utils.h \
	mode_mngr.h \
	error_code.h \
	open_wrapper.h \
	piper.h \
	redirect_util.h \
	redirect.h \
	expander.h \
	shell_op.h \
	macro.h \
	tab.h \
	pipe.h \
	parser.h \
	pipe_list.h \
	token.h \
	main.h \
	token_list.h \
	env.h \
	mini_signal.h \
	executer.h \
	cmd.h \
	laxer.h \
	commander.h \
	pipe_pair.h \
	cmd_list.h \
	redirect_list.h \
	builtin.h \
	mini_util.h \
	reader.h \
	heredoc_utils.h \
	redirecter.h \
	cleaner.h \
	heredoc.h \
	dup_wrapper.h

HEAD 					= $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

#---------- SRC ----------
SRC_DIR 				= src
SRC 					= \
	src/heredoc/heredoc.c \
	src/heredoc/heredoc_child.c \
	src/mode_mngr/mode_mngr.c \
	src/pipe/pipe.c \
	src/env/env_utils.c \
	src/env/env.c \
	src/env/env_utils2.c \
	src/piper/piper.c \
	src/piper/piper_is.c \
	src/piper/piper_child.c \
	src/builtin/builtin_cd.c \
	src/builtin/builtin_echo.c \
	src/builtin/builtin_unset.c \
	src/builtin/builtin.c \
	src/builtin/builtin_exit.c \
	src/builtin/builtin_export_util.c \
	src/builtin/builtin_env.c \
	src/builtin/builtin_pwd.c \
	src/builtin/builtin_export.c \
	src/dll/dll_iterate.c \
	src/dll/dll_add.c \
	src/dll/dll.c \
	src/dll/dll_is.c \
	src/dll/dll_swap.c \
	src/dll/dll_remove.c \
	src/dll/dll_get.c \
	src/redirect_util/redirect_util2.c \
	src/redirect_util/redirect_util.c \
	src/error_code/error_code.c \
	src/executer/executer_child.c \
	src/executer/executer.c \
	src/executer/executer_builtin.c \
	src/executer/executer_many_cmds.c \
	src/shell_op/shell_op_get.c \
	src/shell_op/shell_op_set.c \
	src/shell_op/shell_op.c \
	src/laxer/laxer.c \
	src/laxer/laxer_get_token_type.c \
	src/parser/parser_syntax.c \
	src/parser/parser.c \
	src/pipe_list/pipe_list.c \
	src/pipe_list/pipe_list_close.c \
	src/redirecter/redirecter_child.c \
	src/redirecter/redirecter.c \
	src/redirecter/redirecter_builtin.c \
	src/token/token.c \
	src/token/token_print.c \
	src/open_wrapper/open_wrapper.c \
	src/token_list/token_list.c \
	src/token_list/token_list_print.c \
	src/redirect/redirect.c \
	src/main/main_internal.c \
	src/main/main_internal_loop.c \
	src/main/main.c \
	src/commander/commander_exec_path.c \
	src/commander/commander_util.c \
	src/commander/commander_path_tab.c \
	src/commander/commander_iter.c \
	src/commander/commander.c \
	src/mini_signal/mini_signal_heredoc.c \
	src/mini_signal/mini_signal.c \
	src/pipe_pair/pipe_pair_init.c \
	src/pipe_pair/pipe_pair.c \
	src/cmd_list/cmd_list_get.c \
	src/cmd_list/cmd_list_iter.c \
	src/cmd_list/cmd_list.c \
	src/redirect_list/redirect_list.c \
	src/cmd/cmd_set.c \
	src/cmd/cmd.c \
	src/expander/expander_utils2.c \
	src/expander/expander_qoute_logic.c \
	src/expander/expander_tilde.c \
	src/expander/expander_utils.c \
	src/expander/expander.c \
	src/expander/expander_quotes.c \
	src/reader/reader_cli.c \
	src/reader/reader_split_smart.c \
	src/reader/reader_files.c \
	src/reader/reader_utils2.c \
	src/reader/reader_utils.c \
	src/reader/reader.c \
	src/tab/tab2.c \
	src/tab/tab.c \
	src/mini_util/mini_util.c \
	src/cleaner/cleaner.c \
	src/dup_wrapper/dup_wrapper.c \
	src/filer/filer.c

#---------- OBJ ----------
OBJ_DIR 				= obj
OBJ						= $(subst $(SRC_DIR),$(OBJ_DIR), $(SRC:.c=.o))
OBJ_NO_MAIN	 			= $(filter-out obj/main/main.o,$(OBJ))

#---------- LIBFT ----------
LIBFT_NAME				= libft.a
LIBFT_DIR				= libft
LIBFT_HEAD_DIR			= $(LIBFT_DIR)
LIBFT					= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

#---------- FLAGS ----------
READLINE_HEADER			= /Users/$(USER)/.brew/opt/readline/include
READLINE_LIB			= /Users/$(USER)/.brew/opt/readline/lib
CC 						= cc
HEAD_FLAG				= -I$(HEAD_DIR) -I$(LIBFT_HEAD_DIR) -I$(READLINE_HEADER)
CFLAGS 					= -c -Wall -Wextra -Werror $(HEAD_FLAG)
LDFLAGS 				= -L$(LIBFT_DIR) -L$(READLINE_LIB)
LDLIBS 					= -lpthread -lft -lreadline

#---------- IMPLICT RULES ----------
$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) $(HEAD)
	$(CC) $(CFLAGS) $< -o $(@)

#---------- RULES ----------
.PHONY: clean fclean re all

all: $(OBJ_DIR) $(NAME)

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(OBJ_DIR):
	cp -a $(SRC_DIR) $(OBJ_DIR)
	$(RM) $(OBJ:.o=.c)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

clean:
	$(MAKE) clean -sC $(LIBFT_DIR)
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all


