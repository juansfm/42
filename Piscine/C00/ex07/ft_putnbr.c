/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:07:42 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/15 16:15:37 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, &"-", 1);
		write(1, &"2147483648", 10);
		return ;
	}	
	if (nb < 0 && nb != -2147483648)
	{
		write (1, &"-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr (nb / 10);
	}
	ft_putchar ('0' + nb % 10);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
