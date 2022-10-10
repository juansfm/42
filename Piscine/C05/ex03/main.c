/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:54:35 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/01 16:57:48 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_recursive_power(int nb, int power);

int main(void)
{
	int nb;
	int power;

	nb = -6;
	power = 0;
	printf("%d\n",ft_recursive_power(nb, power));
}
