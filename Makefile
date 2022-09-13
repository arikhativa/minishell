# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/09/12 14:51:50 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makefile_util.mk

NAME 			= minishell

#---------- HEAD ----------
HEAD_DIR 		= include
HEAD_NAME 		= $(notdir $(wildcard $(HEAD_DIR)/*.h))
HEAD 			= $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

#---------- SRC ----------
SRC_DIR 		= src
SRC 			= $(wildcard $(SRC_DIR)/**/*.c)

#---------- OBJ ----------
OBJ_DIR 		= obj
OBJ				= $(subst $(SRC_DIR),$(OBJ_DIR), $(SRC:.c=.o))

#---------- LIBFT ----------
LIBFT_NAME		= libft.a
LIBFT_DIR		= libft
LIBFT_HEAD_DIR	= $(addprefix $(LIBFT_DIR)/, libft)
LIBFT			= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

#---------- TEST ----------
TEST_DIR		= unit_test
TEST_HEAD_DIR	= -I$(TEST_DIR) -I$(HEAD_DIR)
TEST_LDLIBS		= -lcunit 
TEST_EXEC		= test.out
TEST_RES		= "unit_test_result.txt"
TEST_CFLAGS		= -D TEST_RES='$(TEST_RES)'
TEST_SRC 		= $(wildcard $(TEST_DIR)/**/*.t.c)
TEST_OUT 		= $(TEST_SRC:.t.c=.t.out)

#---------- FLAGS ----------
CC 				= cc
I_FLAG 			= -I$(HEAD_DIR) -I$(LIBFT_HEAD_DIR)
CFLAGS 			= -c -Wall -Wextra -Werror $(I_FLAG)
LDFLAGS 		= -L$(LIBFT_DIR)
LDLIBS 			= -lpthread -lft

#---------- IMPLICT RULES ----------
$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) $(HEAD)
	@mkdir -p  $(OBJ_DIR)
	@$(CC) $(CFLAGS) $< -o $(@)

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

clean:
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(RM) $(OBJ)
	@echo "$(RED)Objects Removed!$(NC)"

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) Removed!$(NC)"

re: fclean $(NAME)

$(addprefix $(TEST_DIR)/, %.t.out): $(addprefix $(OBJ_DIR)/, %.o) $(addprefix $(TEST_DIR)/, %.t.c)
	@$(CC) $(TEST_CFLAGS) $^ $(TEST_HEAD_DIR) $(TEST_LDLIBS) -o $@
	@./$@
	@$(RM) $@
	@$(RM) $(TEST_RES)

check: $(TEST_OUT)
