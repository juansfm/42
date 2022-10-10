/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:00:17 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/31 16:20:03 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_error(char *str)
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

void	ft_putnbr_base(int nbr, char *base)
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
		write (1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= len && nbr != -2147483648)
		ft_putnbr_base(nbr / len, base);
	i = nbr % len;
	write(1, &base[i], 1);
	return ;
}
