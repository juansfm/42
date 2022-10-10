/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:43:55 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/01 17:49:58 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb < 2)
		return (0);
	else if (nb == 2)
		return (1);
	else
	{
		while (i <= ft_sqrt(nb))
		{
			if (nb % i == 0 || nb % 2 == 0)
				return (0);
			i += 2;
		}
	}
	return (1);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		nb -= i;
		i += 2;
	}
	if (nb == 0)
		return ((i - 1) / 2);
	else
		return ((i - 3) / 2);
}
