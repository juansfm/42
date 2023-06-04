/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:28:09 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/26 19:07:56 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_line(char *buffer);
char	*ft_buffer(char *buffer);
char	*ft_read(int fd, char *buffer);
size_t	ft_strlen(const char *s);
size_t	ft_gnl_strchr(char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);

#endif
