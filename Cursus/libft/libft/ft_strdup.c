/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:10:34 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/26 16:54:48 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc((ft_strlen(s1) +1) * sizeof(char));
	if (s2 != NULL)
	{
		while (i < ft_strlen(s1) + 1)
		{
			s2[i] = s1[i];
			i++;
		}
		return (s2);
	}
	return (0);
}
