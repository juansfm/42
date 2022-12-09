/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:21 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/12/09 13:52:32 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer_line;
	char		*line;

	printf("%d", fd);
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer_line)
	{
		buffer_line = (char *)malloc(1 * sizeof(*buffer_line));
		if (!buffer_line)
		{
			free(buffer_line);
			return (NULL);
		}
		buffer_line = 0;
	}
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	line = ft_read(fd, buffer_line);
	printf("%s\n", line);
	if (line == NULL)
		return (free(buffer_line), NULL);
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	ssize_t	numberbytes;
	char	*temp;

	numberbytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (numberbytes > 0)
	{
		numberbytes = read(fd, temp, BUFFER_SIZE);
		printf("%s", temp);
		if (numberbytes < 0)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		temp[numberbytes] = '\0';
		buffer = ft_join(buffer, temp);
		if (buffer == NULL)
			return (free(buffer), NULL);
		if (ft_strchr(temp, '\n'))
		{
			ft_endline(temp, buffer);
			break ;
		}
	}
	return (buffer);
}

char	*ft_join(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

char	*ft_endline(char *buffer, char *temp)
{
	char	*str;
	size_t	i;

	if (buffer == NULL && temp == NULL)
		return (0);
	i = 0;
	while (i < ft_strlen(buffer))
	{
		if (buffer[i] == '\n')
		{
			str = ft_substr(buffer, 0, i);
			temp = ft_join(temp, str);
			free(str);
			buffer = ft_strchr(buffer, '\n');
			return (temp);
		}
		i++;
	}
	return (0);
}
