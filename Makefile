# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 22:01:15 by alopez-g          #+#    #+#              #
#    Updated: 2022/09/04 09:57:07 by al7aro-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[0;31m
CYAN			= \033[0;36m
GREEN 			= \033[1;32m
YELLOW 			= \033[1;33m
NC 				= \033[0m

DIR 			= .
NAME 			= minishell

#---------- LIBS ---------------------------------------------------------------
	#---------- FTPF -----------------------------------------------------------
M_FTPF 			= $(FTPF_DIR)/Makefile

FTPF_LIB		= ftprintf
FTPF_DIR 		= $(DIR)/src/ft_printf
FTPF_SRC_DIR 	= $(DIR)/src/ft_printf/srcs
FTPF_SRC 		= $(wildcard $(FTPF_SRC_DIR)/*.c)
FTPF_A 			= $(FTPF_DIR)/lib$(FTPF_LIB).a

I_FTPF 			= $(FTPF_DIR)/includes
I_FTPF_H 		= $(I_FTPF)ftpritf.h

	#---------- LIBFT ----------------------------------------------------------
M_LIBFT 		= $(LIBFT_DIR)/Makefile

LIBFT_DIR 		= $(FTPF_DIR)/srcs/Libft
LIBFT_SRC_DIR 	= $(DIR)/src/ft_printf/srcs/Libft/srcs
LIBFT_SRC 		= $(wildcard $(LIBFT_SRC_DIR)/*.c)

I_LIBFT 		= $(LIBFT_DIR)/includes
I_LIBFT_H	 	= $(I_LIBT)/libft.h

#---------- PUSH SWAP ----------------------------------------------------------
#---------- INCLUDES ----------
I_DIR 			= $(DIR)/includes
I_H 			= minishell.h
I 				= $(patsubst %.h, $(I_DIR)/%.h, $(I_H))

#---------- SRC ----------
SRC_DIR 		= $(DIR)/src
#SRC_COLOR 		= $(SRC_DIR)/colors
#SRC_INSTR 		= $(SRC_DIR)/instr
#SRC_COLOR_C 	= color.c
#SRC_INSTR_C 	= exec.c s.c p.c r.c rr.c 
SRC_MS_C 		= main.c
SRC 			= $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_MS_C)) \
#					$(patsubst %.c, $(SRC_COLOR)/%.c, $(SRC_COLOR_C)) \
#					$(patsubst %.c, $(SRC_INSTR)/%.c, $(SRC_INSTR_C)) 
#---------- OBJ ----------
BUILD_DIR 		= $(SRC_DIR)/build

OBJ_MS 			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, \
		 			$(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_MS_C)))
#OBJ_INSTR 		= $(patsubst $(SRC_INSTR)/%.c, $(BUILD_DIR)/%.o, \
#					$(patsubst %.c, $(SRC_INSTR)/%.c, $(SRC_INSTR_C)))
#OBJ_COLOR 		= $(patsubst $(SRC_COLOR)/%.c, $(BUILD_DIR)/%.o, \
					$(patsubst %.c, $(SRC_COLOR)/%.c, $(SRC_COLOR_C)))
OBJ 			= $(OBJ_MS) #$(OBJ_INSTR) $(OBJ_COLOR)

#---------- FLAGS ----------
CC 				= gcc
FLAGS 			= -Wall -Wextra -Werror
I_FLAG 			= -I $(I_DIR)/ -I $(I_FTPF)/ -I $(I_LIBFT)/

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
				@$(CC) $(FLAGS) $(I_FLAG)  -c $< -o $@
#$(BUILD_DIR)/%.o : $(SRC_INSTR)/%.c
#				@$(CC) $(FLAGS) $(I_FLAG)  -c $< -o $@
#$(BUILD_DIR)/%.o : $(SRC_COLOR)/%.c
#				@$(CC) $(FLAGS) $(I_FLAG)  -c $< -o $@
#-------------------------------------------------------------------------------

all: $(NAME)
$(NAME): $(OBJ) $(FTPF_SRC) $(M_FTPF) $(LIBFT_SRC) $(M_LIBFT) $(I)
				@echo "${RED}Compiling LIBFTPRINTF${NC}\c"
				@make -s -C $(FTPF_DIR)
				@echo " ---> ${CYAN}Success${NC}"
				@$(CC) $(FLAGS) $(OBJ) -L$(FTPF_DIR) -l$(FTPF_LIB) -o minishell
				@echo "${GREEN}${NAME} READY!${NC}"
clean:
				@make -s -C $(FTPF_DIR) clean
				@rm -rf $(BUILD_DIR)/*
				@echo "${YELLOW}OBJS Removed!${NC}"
fclean: clean
				@make -s -C $(FTPF_DIR) fclean
				@rm -rf $(NAME)
				@echo "${YELLOW}$(NAME) Removed!${NC}"
re: fclean $(NAME)

debug: FLAGS = -g -D DEBUG
debug: re

.PHONY: clean fclean re
