/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:42:20 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/02/23 11:38:16 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
		return (NULL);
	buffer = ft_buffer(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	size_t	len;
	char	*line;
	size_t	i;

	i = 0;
	len = ft_strchr(buffer, '\n');
	if (len == 0)
		len = ft_strlen(buffer) + 1;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (free(buffer), free(line), NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (i < ft_strlen(buffer))
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_buffer(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			i++;
			j = 0;
			temp = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
			while (buffer[i] != '\0')
			{
				temp[j] = buffer[i];
				i++;
				j++;
			}
			temp[j] = '\0';
			return (free(buffer), temp);
		}
		i++;
	}
	return (free(buffer), NULL);
}

char	*ft_read(int fd, char *buffer)
{
	int		numbytes;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	numbytes = read(fd, temp, BUFFER_SIZE);
	if (numbytes < 0)
		return (free(temp), free(buffer), NULL);
	if (numbytes == 0 && ft_strlen(buffer) == 0)
		return (free(temp), free(buffer), NULL);
	temp[numbytes] = '\0';
	buffer = ft_strjoin(buffer, temp);
	while (numbytes > 0 && !ft_strchr(temp, '\n'))
	{
		numbytes = read(fd, temp, BUFFER_SIZE);
		if (numbytes < 0)
			return (free(temp), free(buffer), NULL);
		if (numbytes == 0 && ft_strlen(buffer) == 0)
			return (free(temp), free(buffer), NULL);
		temp[numbytes] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	return (free(temp), buffer);
}
