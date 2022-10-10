/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:25:22 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/01 14:31:53 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	fact;

	fact = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb >= 1)
	{
		fact = fact * nb;
		nb--;
	}
	return (fact);
}
