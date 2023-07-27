# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 10:55:47 by jsaavedr          #+#    #+#              #
#    Updated: 2023/07/14 12:38:38 by jsaavedr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAMEC = client

SERVER = server.c
SERVER_OBJS = ${SERVER:.c=.o}

CLIENT = client.c
CLIENT_OBJS = ${CLIENT:.c=.o}

LIBFT = library/libft/libft.a

PRINTF = library/ft_printf/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME} ${NAMEC}

${NAME}: ${LIBFT} ${PRINTF} ${SERVER_OBJS}
	@${CC} ${CFLAGS} ${SERVER_OBJS} ${LIBFT} ${PRINTF} -o ${NAME}

${NAMEC}: ${LIBFT} ${PRINTF} ${CLIENT_OBJS}
	@${CC} ${CFLAGS} ${CLIENT_OBJS} ${LIBFT} ${PRINTF} -o ${NAMEC}
	
${LIBFT}:
	@make -C library/libft

${PRINTF}:
	@make -C library/ft_printf

clean:
	@make clean -C library/libft
	@make clean -C library/ft_printf
	@${RM} ${SERVER_OBJS} ${CLIENT_OBJS} ${SERVER_BONUS_OBJS} ${CLIENT_BONUS_OBJS}

fclean: clean
	@make fclean -C library/libft
	@make fclean -C library/ft_printf
	@${RM} server client

re: fclean all

.PHONY: all clean fclean re bonus