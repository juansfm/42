/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:15:07 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/16 16:41:11 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putstr("2147483648");
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10);
	}
	ft_putchar('0' + n % 10);
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

void	ft_putnbr_base(int c, char *base)
{
	int	i;
	int	len;

	if (ft_error(base) == 0)
		return ;
	len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base((nbr % len) * -1, base);
	}
	if (nbr < 0 && nbr != -2147483648)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= len && nbr != -2147483648)
		ft_putnbr_base(nbr / len, base);
	i = nbr % len;
	write(1, &base[i], 1);
	return ;
}
