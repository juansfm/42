/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:21 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/12/11 13:39:49 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer_line;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer_line)
	{
		buffer_line = (char *)malloc(1 * sizeof(*buffer_line));
		if (!buffer_line)
			return (NULL);
		buffer_line = 0;
	}
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (free(buffer_line), NULL);
	line = ft_read(fd, buffer_line);
	if (line == NULL)
		return (NULL);
	buffer_line = ft_strchr(line, '\n');
	line = ft_endline(line);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	ssize_t	numberbytes;
	char	*temp;

	numberbytes = 1;
	while (numberbytes > 0)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		numberbytes = read(fd, temp, BUFFER_SIZE);
		if (numberbytes < 0)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, temp);
		if (buffer == NULL)
			return (free(buffer), NULL);
		if (ft_strchr(temp, '\n') || numberbytes < BUFFER_SIZE)
			break ;
		free(temp);
	}
	return (buffer);
}

char	*ft_endline(char *line)
{
	size_t	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] == '\n')
			line = ft_substr(line, 0, i);
		i++;
	}
	return (line);
}
