/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:05:44 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/29 11:06:48 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
void ft_rev_int_tab(int *tab, int size);
int main(void)
{
	int size = 5;
	int tab[5] =  {6, 2, 44, 4, 39};
	int z;

	z=0;
	while(z < size)
	{
		printf("%d\n",tab[z]);
		z++;
	}
	ft_rev_int_tab(tab, size);
	z=0;
	while(z < size)
	{
		printf("%d\n",tab[z]);
		z++;
	}
}
