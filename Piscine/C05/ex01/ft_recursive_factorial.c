/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:31:01 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/01 14:43:40 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	fact;

	fact = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	fact = nb * ft_recursive_factorial(nb -1);
	return (fact);
}
