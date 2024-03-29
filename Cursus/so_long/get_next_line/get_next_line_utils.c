/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:42:16 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/26 19:08:03 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_gnl_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	k;
	char	*str;

	if ((!s1 && !s2) || !s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	k = -1;
	while (s1[++k] != '\0')
	{
		str[k] = s1[k];
	}
	while (s2[k - ft_strlen(s1)] != '\0')
	{
		str[k] = s2[k - ft_strlen(s1)];
		k++;
	}
	str[k] = '\0';
	return (free(s1), str);
}
