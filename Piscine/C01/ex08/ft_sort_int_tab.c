/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:48:48 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/23 10:32:36 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	aux;
	int	z;
	int	zz;

	aux = tab[0];
	z = 0;
	while (z < size)
	{
		zz = z +1;
		while (zz < size)
		{
			if (tab[zz] < tab[z])
			{
				aux = tab[z];
				tab[z] = tab[zz];
				tab[zz] = aux;
			}
			zz++;
		}
		z++;
	}
}
