# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 11:26:43 by yoav              #+#    #+#              #
#    Updated: 2022/09/17 12:58:21 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strlen.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strcmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strdup.c \
	ft_calloc.c \
	ft_atoi.c \
	ft_strchr.c \
	ft_strtrim.c \
	ft_strjoin.c \
	ft_strnstr.c \
	ft_memset.c \
	ft_itoa.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_split.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_substr.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_bzero.c

BONUS_SRC = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstadd_back.c \
	ft_lstlast.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstmap.c \
	ft_lstiter.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEAD = libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
ARFLAGS = rcs

.PHONY: clean fclean re all bonus

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus: $(BONUS_OBJ) $(OBJ) $(HEAD)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
