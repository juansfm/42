/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:21 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/02/13 16:05:55 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer_line;
	char		*line;

	buffer_line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (free(line), free(buffer_line), buffer_line = NULL, NULL);
	line = ft_read(fd, buffer_line);
	if (line == NULL)
		return (free(line), free(buffer_line), buffer_line = NULL, NULL);
	buffer_line = ft_buffer(buffer_line, line);
	line = ft_line(line);
	if (line == NULL)
		return (free(line), free(buffer_line), buffer_line = NULL, NULL);
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	ssize_t	numberbytes;
	char	*temp;

	numberbytes = BUFFER_SIZE;
	while (numberbytes == BUFFER_SIZE && !ft_strchr(buffer, '\n'))
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (temp == NULL)
			return (free(temp), temp = NULL, NULL);
		numberbytes = read(fd, temp, BUFFER_SIZE);
		if (numberbytes < 0)
			return (free(temp), temp = NULL, NULL);
		temp[numberbytes] = '\0';
		if (numberbytes == 0)
			return (free(buffer), buffer = NULL, temp);
		buffer = ft_join(buffer, temp);
		if (buffer == NULL)
			return (free(temp), temp = NULL, NULL);
		free(temp);
		temp = NULL;
	}
	return (buffer);
}

char	*ft_buffer(char *buffer, char *line)
{
	char	*temp;
	int		i;

	temp = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	temp = line;
	i = 0;
	if (ft_strchr(buffer, '\n'))
		buffer = ft_substr(temp, ft_strchr(line, '\n'), ft_strlen(temp));
	if (buffer == NULL)
		return (free(buffer), buffer = NULL, NULL);
	return (buffer);
}

char	*ft_line(char *line)
{
	size_t	i;

	if (line == NULL)
		return (free(line), NULL);
	i = 0;
	line = ft_substr(line, 0, ft_strchr(line, '\n') - 1);
	if (line == NULL)
		return (free(line), line = NULL, NULL);
	return (line);
}

char	*ft_join(char *s1, char *s2)
{
	char	*aux;

	if (!s2)
		return (NULL);
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
	}
	aux = ft_strjoin(s1, s2);
	free(s1);
	s1 = NULL;
	return (aux);
}
