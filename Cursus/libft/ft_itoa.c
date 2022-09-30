/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:28:28 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/29 17:21:38 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	sign;
	char	*str;

	if (n == -2147483648)
	{
		str = (char *)ft_calloc(11, sizeof(char));
		str = "-2147483648";
		return (str);
	}
	sign = '+';
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		sign = '-';
		len = 1;
	}
	i = n;
	while (i > 0)
	{
		len++;
		i = i / 10;
	}
	str = (char *)ft_calloc((len +1), sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	if (sign == '-')
		str[0] = '-';
	if (n > 9)
		str = ft_itoa(n / 10);
	while (str[i] != '\0')
		i++;
	str[i] = n % 10 + '0';
	return (str);
}
