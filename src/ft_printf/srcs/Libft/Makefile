# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 17:06:37 by aloez-g           #+#    #+#              #
#    Updated: 2022/08/20 20:39:58 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTPF_INC	=	../../includes
LIBFT_INC	=	includes
SRC_DIR		=	./srcs
SRC			=	${SRC_DIR}/ft_memset.c				${SRC_DIR}/ft_bzero.c \
				${SRC_DIR}/ft_memcpy.c 				${SRC_DIR}/ft_memccpy.c \
				${SRC_DIR}/ft_memmove.c 			${SRC_DIR}/ft_memchr.c \
				${SRC_DIR}/ft_memcmp.c 				${SRC_DIR}/ft_strlen.c \
				${SRC_DIR}/ft_strlcpy.c 			${SRC_DIR}/ft_strlcat.c \
				${SRC_DIR}/ft_strchr.c 				${SRC_DIR}/ft_strrchr.c \
				${SRC_DIR}/ft_strnstr.c 			${SRC_DIR}/ft_strncmp.c \
				${SRC_DIR}/ft_atoi.c 				${SRC_DIR}/ft_isalpha.c \
				${SRC_DIR}/ft_isdigit.c 			${SRC_DIR}/ft_isalnum.c \
				${SRC_DIR}/ft_isascii.c				${SRC_DIR}/ft_isprint.c \
				${SRC_DIR}/ft_toupper.c 			${SRC_DIR}/ft_tolower.c \
				${SRC_DIR}/ft_calloc.c 				${SRC_DIR}/ft_strdup.c\
				${SRC_DIR}/ft_substr.c 				${SRC_DIR}/ft_strjoin.c \
				${SRC_DIR}/ft_strtrim.c 			${SRC_DIR}/ft_split.c \
				${SRC_DIR}/ft_itoa.c 				${SRC_DIR}/ft_strmapi.c \
				${SRC_DIR}/ft_putchar_fd.c 			${SRC_DIR}/ft_putstr_fd.c \
				${SRC_DIR}/ft_putendl_fd.c 			${SRC_DIR}/ft_putnbr_fd.c \
				${SRC_DIR}/ft_uitoab.c 				${SRC_DIR}/ft_ultoab.c \
				${SRC_DIR}/ft_lstnew_bonus.c	 	${SRC_DIR}/ft_lstadd_front_bonus.c \
				${SRC_DIR}/ft_lstsize_bonus.c 		${SRC_DIR}/ft_lstlast_bonus.c \
				${SRC_DIR}/ft_lstadd_back_bonus.c	${SRC_DIR}/ft_lstdelone_bonus.c \
				${SRC_DIR}/ft_lstclear_bonus.c 		${SRC_DIR}/ft_lstiter_bonus.c \
				${SRC_DIR}/ft_lstmap_bonus.c		${SRC_DIR}/ft_lstdelrange_bonus.c \
				${SRC_DIR}/ft_atof.c 				${SRC_DIR}/ft_ftoa.c \
				${SRC_DIR}/ft_ultoa.c

BUILD_DIR	=	$(SRC_DIR)/build
OBJS		= 	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
I_FLAG		=	-I $(FTPF_INC) -I $(LIBFT_INC)

$(BUILD_DIR)/%.o	: $(SRC_DIR)/%.c
			@mkdir -p $(BUILD_DIR)
			@$(CC) $(FLAGS) $(I_FLAG) -c $< -o $@

NAME		= 	libft.a

all:			${NAME}
$(NAME):		build_dir $(OBJS)
				@ar -rc ${NAME} ${OBJS}
				@ar -s ${NAME}
clean:
				@rm -f ${OBJS}
fclean:			clean
				@rm -f ${NAME}
re:				fclean all
build_dir:
				@mkdir -p $(BUILD_DIR)
.PHONY:			all clean fclean re
