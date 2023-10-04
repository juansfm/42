# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 12:04:26 by jsaavedr          #+#    #+#              #
#    Updated: 2023/10/04 19:10:03 by jsaavedr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philosophers.c libft.c threads.c actions.c utils.c checks.c forks.c mutex.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread
RM = rm -f


all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	
fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re