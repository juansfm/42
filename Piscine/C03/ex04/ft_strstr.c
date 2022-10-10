/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:43:17 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/29 12:22:20 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*dev;

	i = 0;
	if (to_find[0] == '\0')
		return (dev = &str[0]);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j +1] == '\0')
				return (dev = &str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
