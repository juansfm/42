/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:18:51 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/16 13:02:48 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

int main(void)
{
	int a=-120;
	int b=50;
	int *ap;
	int *bp;

	ap = &a;
	bp = &b;
	ft_ultimate_div_mod(ap, bp);
	printf("%d\n",*ap);
	printf("%d\n",*bp);
}
