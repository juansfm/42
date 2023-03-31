# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 11:57:13 by jsaavedr          #+#    #+#              #
#    Updated: 2023/03/27 12:43:23 by jsaavedr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES	= -I ./

NAME	= push_swap

SRCS	= push_swap.c push_swap_2.c \
		libft_1.c libft_2.c \
		movement_1.c

OBJS	= {SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

AR 	= ar crs ${INCLUDES}

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re