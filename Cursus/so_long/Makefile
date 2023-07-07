# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 18:29:55 by jsaavedr          #+#    #+#              #
#    Updated: 2023/07/01 18:54:18 by jsaavedr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

SRCS = so_long.c checks.c path.c game.c images.c
GNL_SRCS = get_next_line.c get_next_line_utils.c

OBJS_DIR = objs/
SRCS_DIR = srcs/
GNL_DIR = get_next_line/

SRCS_OBJS = ${addprefix ${OBJS_DIR}${SRCS_DIR}, ${SRCS:.c=.o}}
GNL_OBJS = ${addprefix ${OBJS_DIR}${GNL_DIR}, ${GNL_SRCS:.c=.o}}

LIBFT = library/libft/libft.a
MLX = library/MLX42/libmlx42.a
MLX_INC = -L "/Users/${USER}/.brew/opt/glfw/lib/" -I ./MLX42/include

HDR_DIR = includes/
HDR = so_long.h
HDR_PATH = ${addprefix ${HDR_DIR}, ${HDR}}
HDR_INC = -I ./includes

all:	${NAME}

${NAME}:	${MLX} ${LIBFT} ${OBJS_DIR}${SRCS_DIR} ${OBJS_DIR}${GNL_DIR} ${SRCS_OBJS} ${GNL_OBJS} ${HDR_PATH}
		@${CC} ${CFLAGS} ${SRCS_OBJS} ${GNL_OBJS} ${MLX} ${LIBFT} -o $@ -lglfw ${MLX_INC}

${MLX}:
		@make -C library/MLX42

${LIBFT}:
		@make -C library/libft

${OBJS_DIR}:
		@mkdir $@

${OBJS_DIR}${SRCS_DIR}: ${OBJS_DIR}
		@mkdir $@

${OBJS_DIR}${GNL_DIR}: ${OBJS_DIR}
		@mkdir $@

${OBJS_DIR}${SRCS_DIR}%.o: ${SRCS_DIR}%.c ${HDR_PATH}
		@${CC} ${CFLAGS} ${HDR_INC} -o $@ -c $<

${OBJS_DIR}${GNL_DIR}%.o: ${GNL_DIR}%.c ${HDR_PATH}
		@${CC} ${CFLAGS} -o $@ -c $<
clean:
		@${RM} ${OBJS_DIR}
		@${MAKE} -s -C library/libft/ clean
		@${MAKE} -s -C library/MLX42/ clean
		

fclean:	clean
		@${RM} ${NAME}
		@${MAKE} -s -C library/libft/ fclean
		@${MAKE} -s -C library/MLX42/ fclean

re:	fclean all

.PHONY:	all clean fclean re