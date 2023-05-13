/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:18:31 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/05/13 18:04:12 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	total;
	char	*str;

	if (start > ft_strlen(s))
		return (NULL);
	if (ft_strlen(s) - start < len && start < ft_strlen(s))
		total = ft_strlen(s) - start + 1;
	else
		total = len + 1;
	str = malloc(total * sizeof(char));
	if (str != NULL)
	{
		i = start;
		while (i < len + start && i < ft_strlen(s))
		{
			str[i - start] = s[i];
			i++;
		}
		str[i - start] = '\0';
		return (str);
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
			return (1);
		else if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
			return (-1);
		i++;
	}
	return (0);
}
