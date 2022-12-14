/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:39:06 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/08 20:28:49 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	total;
	char	*str;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len && start < ft_strlen(s))
		total = ft_strlen(s) - start + 1;
	else
		total = len + 1;
	str = (char *)ft_calloc(total, sizeof(char));
	if (str != NULL)
	{
		i = start;
		while (i < len + start && i < ft_strlen(s))
		{
			str[i - start] = s[i];
			i++;
		}
		return (str);
	}
	return (0);
}
