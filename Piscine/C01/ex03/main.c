/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:44:22 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/16 12:18:40 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
	int a=-120;
	int b=50;
	int div;
	int mod;
	int *divp;
	int *modp;

	divp = &div;
	modp = &mod;
	ft_div_mod(a,b,divp,modp);
	printf("%d\n", *divp);
	printf("%d\n", *modp);
}
