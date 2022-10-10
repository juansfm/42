/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:15:33 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/16 11:44:10 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_swap(int *a, int *b);

int main(void)
{
	int c=42;
	int d=24;
	int *a;
	int *b;

	a = &c;
	b = &d;
	ft_swap(a, b);
	printf("%d\n", *a);
	printf("%d\n", *b);
}
