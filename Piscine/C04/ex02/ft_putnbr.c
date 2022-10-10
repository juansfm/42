/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:17:30 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/28 11:33:40 by jsaavedr         ###   ########.fr       */
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
