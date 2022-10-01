/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:28:28 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/01 16:44:37 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*fill_str(char *str, unsigned int n, int len);
static unsigned int	negative_numbers(int num, unsigned int *len, char *sign);

char	*ft_itoa(int num)
{
	unsigned int	n;
	unsigned int	len;
	unsigned int	i;
	char			sign;
	char			*str;

	sign = '+';
	len = 1;
	n = negative_numbers(num, &len, &sign);
	i = n;
	while (i / 10 > 9)
	{
		len++;
		i = i / 10;
	}
	str = (char *)ft_calloc((len +1), sizeof(char));
	if (str == NULL)
		return (0);
	if (sign == '-')
	{
		str[0] = sign;
		i++;
	}
	str = fill_str(str, n, len);
	return (str);
}

static char	*fill_str(char *str, unsigned int n, int len)
{
	int	i;
	int	j;
	int	k;
	int	tenpower;

	i = 0;
	if (str[0] == '-')
		i = 1;
	j = len +1;
	while (i < len)
	{
		str[i] = n % 10 + '0';
		k = 1;
		tenpower = 1;
		while (k < j)
		{
			tenpower *= 10;
			k++;
		}
		n = n / tenpower;
		j--;
		i++;
	}
	return (str);
}

static unsigned int	negative_numbers(int num, unsigned int *len, char *sign)
{
	unsigned int	n;

	if (num == -2147483648)
	{
		n = 2147483648;
		*sign = '-';
		*len = 2;
	}
	else if (num < 0)
	{
		*sign = '-';
		*len = 2;
		n = -num;
	}
	else
		n = num;
	return (n);
}
