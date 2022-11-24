/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:21 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/11/23 16:33:12 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer_line;
	char		*line;
	int			i;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	if (!buffer_line)
	{
		buffer_line = (char *)malloc(1 * sizeof(char));
		if (!buffer_line)
			return (NULL);
	}
	line = NULL;
	i = 0;
	line = ft_read(fd, buffer_line, line);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*ft_read(int fd, char *buffer, char *line)
{
	int		i;
	int		numberbytes;
	char	*temp;

	numberbytes = 1;
	temp = line;
	while (numberbytes > 0)
	{
		i = 0;
		numberbytes = read(fd, buffer, BUFFER_SIZE);
		if (numberbytes == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		if (ft_endline(buffer, temp))
		{
			buffer = ft_strchr(buffer, '\n');
			break ;
		}
		temp = ft_join(temp, buffer);
	}
	return (temp);
}

char	*ft_join(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (temp);
}

int	ft_endline(char *buffer, char *temp)
{
	char	*str;
	int		i;

	i = 0;
	temp = NULL;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			str = ft_substr(buffer, 0, i);
			temp = ft_join(str, temp);
			return (1);
		}
		i++;
	}
	return (0);
}
