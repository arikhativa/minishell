# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 11:26:43 by yoav              #+#    #+#              #
#    Updated: 2022/09/12 10:07:52 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT_DIR	= libft
LIBFT_HEAD_DIR	= $(LIBFT_DIR)
LIBFT	= $(addprefix $(LIBFT_DIR)/, libft.a)

GNL_SRC = get_next_line_utils.c get_next_line.c
GNL_PATH = get_next_line
GNL_OBJ = $(addprefix $(GNL_PATH)/, $(GNL_SRC:.c=.o))
GNL_HEAD_DIR = $(GNL_PATH)
GNL_HEAD = $(addprefix $(GNL_PATH)/, get_next_line.h)

HEAD_DIR = $(GNL_HEAD_DIR) $(LIBFT_HEAD)

CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -I$(GNL_HEAD_DIR)
ARFLAGS = -rcs

%.o: %.c $(GNL_HEAD)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean fclean re bonus

all: $(NAME)

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(NAME): $(GNL_OBJ) $(LIBFT)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(GNL_OBJ)
	
clean:
	$(MAKE) clean -sC $(LIBFT_DIR)
	$(RM) $(GNL_OBJ)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

