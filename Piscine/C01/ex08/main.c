/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:33:41 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/17 19:19:35 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
void ft_sort_int_tab(int *tab, int size);

int main(void)
{
	int size = 5;
	int tab[size];
	int z = 0;

	while (z <= size)
	{
		tab[z]=z+size*z;
		z++;
	}
	z = 0;
	ft_sort_int_tab(tab, size);
	while (z <= size)
	{
		printf("%d\n",tab[z]);
		z++;
	}
}
