/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:00:07 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/01 19:33:49 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);
int	ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (ft_is_prime(i) == 1)
		return (i);
	else
	{
		i++;
		i = ft_find_next_prime(i);
	}
	return (i);
}

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
		return ((i -1) / 2);
	else
		return ((i -3) / 2);
}
