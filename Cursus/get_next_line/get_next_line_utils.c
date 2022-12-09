/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:25 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/12/09 12:07:38 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	k;
	char	*str;

	if (!s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	k = 0;
	while (s1)
	{
		str[k] = s1[k];
		k++;
	}
	printf("%s", str);
	while (s2[k - ft_strlen(s1)] != '\0')
	{
		str[k] = s2[k - ft_strlen(s1)];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	total;
	char	*str;

	if (start > ft_strlen(s))
		return ("\0");
	if (ft_strlen(s) - start < len && start < ft_strlen(s))
		total = ft_strlen(s) - start + 1;
	else
		total = len + 1;
	str = (char *)malloc(total * sizeof(char));
	if (str != NULL)
	{
		i = start;
		while (i < len + start && i < ft_strlen(s))
		{
			str[i - start] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
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

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (i < ft_strlen(s) + 1)
	{
		if (str[i] == (char)c)
			return (free(s), &str[i + 1]);
		i++;
	}
	return (0);
}
