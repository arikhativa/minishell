# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 17:46:30 by alopez-g          #+#    #+#              #
#    Updated: 2022/07/25 04:43:08 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTPF_DIR	=	srcs
LIBFT_DIR	=	srcs/Libft

FTPF_INC	=	includes
LIBFT_INC	=	srcs/Libft/includes
BUILD_DIR	=	$(FTPF_DIR)/build

SRCS		=	${FTPF_DIR}/ft_printf.c ${FTPF_DIR}/struct_utils.c ${FTPF_DIR}/ft_printf_utils.c \
				${FTPF_DIR}/c_flags.c ${FTPF_DIR}/d_flags.c ${FTPF_DIR}/u_flags.c ${FTPF_DIR}/s_flags.c ${FTPF_DIR}/p_flags.c \
				${FTPF_DIR}/apply_utils.c ${FTPF_DIR}/x_flags.c
OBJS		= 	$(patsubst $(FTPF_DIR)/%.c, $(BUILD_DIR)/%.o, ${SRCS})

LIBFT_A		=	${LIBFT_DIR}/libft.a
NAME		=	libftprintf.a

$(BUILD_DIR)/%.o : $(FTPF_DIR)/%.c
				clang -Wall -Werror -Wextra -I $(FTPF_INC) -I $(LIBFT_INC) -c $< -o $@

all:			${NAME}
${NAME}:		build_dir ${OBJS}
				make -C ${LIBFT_DIR}
				cp ${LIBFT_A} ${NAME}
				ar -rc ${NAME} ${OBJS}
				ar -s ${NAME}
bonus:			all
clean:
				make -C ${LIBFT_DIR} clean
				rm -f ${OBJS} ${OBJS_BONUS}
fclean:			clean
				rm -f ${LIBFT_A}
				rm -f ${NAME}
re:				fclean all
build_dir:
				@mkdir -p $(BUILD_DIR)
.PHONY:			all clean fclean re bonus
