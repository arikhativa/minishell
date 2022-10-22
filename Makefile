# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/10/22 05:09:49 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makefile_util.mk

NAME 					= minishell
export ROOT_DIR			= $(CURDIR)

#---------- HEAD ----------
HEAD_DIR 				= include
HEAD_NAME 				= $(notdir $(wildcard $(HEAD_DIR)/*.h))
HEAD 					= $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

#---------- SRC ----------
SRC_DIR 				= src
SRC 					= $(wildcard $(SRC_DIR)/**/*.c)

#---------- OBJ ----------
OBJ_DIR 				= obj
OBJ						= $(subst $(SRC_DIR),$(OBJ_DIR), $(SRC:.c=.o))
OBJ_NO_MAIN	 			= $(filter-out obj/main/main.o,$(OBJ))

#---------- LIBFT ----------
LIBFT_NAME				= libft.a
LIBFT_DIR				= libft
LIBFT_HEAD_DIR			= $(LIBFT_DIR)
LIBFT					= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

#---------- TEST ----------
TEST_DIR				= unit_test
TEST_HEAD_DIR			= $(addprefix $(TEST_DIR)/, include)
TEST_HEAD_NMAE			= $(notdir $(wildcard $(TEST_HEAD_DIR)/*.h))
TEST_HEAD				= $(addprefix $(TEST_HEAD_DIR)/, $(TEST_HEAD_NMAE))
TEST_HEAD_FLAG			= -I$(TEST_HEAD_DIR)
TEST_LDLIBS				= -lcunit $(LDLIBS)
export TEST_EXEC		= test.out
export TEST_RES			= unit_test_result.txt
export VALGRIND_OUTPUT 	= valgrind_out.txt
export NORMINETTE_OUTPUT	= norm_out.txt
export NORMINETTE_RES	= norminette_result.txt
TEST_SRC 				= $(wildcard $(TEST_DIR)/**/*.t.c)
TEST_OBJ 				= $(TEST_SRC:.t.c=.t.o)

#---------- SCRIPT ----------
SCRIPT_DIR				= script
TEST_SCRIPT				= $(addprefix $(SCRIPT_DIR)/, test.sh)

#---------- FLAGS ----------
CC 						= cc
HEAD_FLAG				= -I$(HEAD_DIR) -I$(LIBFT_HEAD_DIR)
CFLAGS 					= -c -Wall -Wextra -Werror $(HEAD_FLAG)
LDFLAGS 				= -L$(LIBFT_DIR)
LDLIBS 					= -lpthread -lft -lreadline

#---------- IMPLICT RULES ----------
$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) $(HEAD)
	@$(CC) $(CFLAGS) $< -o $(@)

$(addprefix $(TEST_DIR)/, %.t.o): $(addprefix $(TEST_DIR)/, %.t.c) $(TEST_HEAD)
	@$(CC) $(CFLAGS) $(TEST_HEAD_FLAG) $< -o $@

#---------- RULES ----------
.PHONY: clean fclean re all check

all: $(OBJ_DIR) $(NAME)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(OBJ_DIR):
	@cp -a $(SRC_DIR) $(OBJ_DIR)
	@$(RM) $(OBJ:.o=.c)

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(GREEN)Compilation was Successful!$(NC)"
	@echo "$(YELLOW)Linking... $(NC)"
	@$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@
	@echo "$(GREEN)$(NAME) READY!$(NC)"

$(TEST_EXEC): $(OBJ_DIR) $(OBJ_NO_MAIN) $(TEST_OBJ) $(LIBFT)
	@$(CC) $(LDFLAGS) $(OBJ_NO_MAIN) $(TEST_OBJ) $(TEST_LDLIBS) -o $(TEST_EXEC)

check: $(TEST_EXEC)
	@bash $(TEST_SCRIPT) unit_test

check/leaks: $(TEST_EXEC)
	@bash $(TEST_SCRIPT) memory

check/norm:
	@bash $(TEST_SCRIPT) norm
	
clean:
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) $(VALGRIND_OUTPUT)
	@$(RM) $(TEST_RES)
	@$(RM) $(TEST_OBJ)
	@echo "$(RED)Objects Removed!$(NC)"

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@$(RM) $(TEST_EXEC)
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) Removed!$(NC)"

re: fclean all


