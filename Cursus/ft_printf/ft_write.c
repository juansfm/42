/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:15:07 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/21 18:11:21 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len = *len + 1;
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		*len = *len + 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	*len = *len + ft_strlen(str);
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, &"-", 1);
		write(1, "2147483648", 10);
		*len = *len + 11;
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		write(1, &"-", 1);
		n = -n;
		*len = *len + 1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
	}
	ft_putchar('0' + n % 10, len);
}

static int	ft_error(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = i +1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == 127 || str[i] <= 32)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_ba(unsigned long long nbr, char *base, int *length)
{
	unsigned int	i;
	unsigned int	len;

	if (ft_error(base) == 0)
		return ;
	len = ft_strlen(base);
	if (nbr >= len)
		ft_putnbr_ba(nbr / len, base, length);
	i = nbr % len;
	write(1, &base[i], 1);
	*length += 1;
	return ;
}
