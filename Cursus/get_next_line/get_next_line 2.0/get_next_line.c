/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:42:20 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/02/11 18:36:39 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			numberbytes;

	if (fd < 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc(sizeof(char));
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	numberbytes = BUFFER_SIZE;
	while (numberbytes > 0 && !ft_strchr(line, '\n'))
	{
		numberbytes = read(fd, line, BUFFER_SIZE);
		if (numberbytes < 0)
			return (free(buffer), NULL);
		line[numberbytes] = '\0';
		buffer = ft_strjoin(buffer, line);
		if (!buffer)
			return (NULL);
	}
	line = ft_line(line, buffer);
	buffer = ft_buffer(buffer);
	return (line);
}

char	*ft_line(char *line, char *buffer)
{
	int	len;

	len = ft_strchr(buffer, '\n');
	if (len == 0)
	{
		line = buffer;
		return (line);
	}
	line = ft_substr(buffer, 0, len);
	return (line);
}

char	*ft_buffer(char *buffer)
{
	char	*aux;
	int		len;

	len = ft_strchr(buffer, '\n');
	if (len == 0)
		return (NULL);
	aux = ft_substr(buffer, len, ft_strlen(buffer));
	return (free(buffer), aux);
}
