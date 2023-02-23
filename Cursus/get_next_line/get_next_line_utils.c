/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:25 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/02/13 15:37:24 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	k;
	char	*str;

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	k = -1;
	while (s1[++k] != '\0')
		str[k] = s1[k];
	while (s2[k - ft_strlen(s1)] != '\0')
	{
		str[k] = s2[k - ft_strlen(s1)];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	total;
	char	*str;

	if (start > ft_strlen(s))
		return (free(s), s = NULL, "");
	if (ft_strlen(s) - start < len && start < ft_strlen(s))
		total = ft_strlen(s) - start + 1;
	else
		total = len + 1;
	str = (char *)malloc(total * sizeof(char));
	if (str != NULL)
	{
		i = start;
		while (i <= len + start && i < ft_strlen(s))
		{
			str[i - start] = s[i];
			i++;
		}
		str[i] = '\0';
		return (free(s), s = NULL, str);
	}
	return (free(str), str = NULL, NULL);
}

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

int	ft_strchr(char *s, int c)
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
