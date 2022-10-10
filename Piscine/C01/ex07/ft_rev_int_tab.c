/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:39:22 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/23 10:31:51 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	z;
	int	aux;

	z = 0;
	while ((z +1) <= (size / 2))
	{
		aux = tab[z];
		tab[z] = tab[size - z -1];
		tab[size - z -1] = aux;
		z++;
	}
}
