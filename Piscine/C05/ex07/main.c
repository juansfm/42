/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:07:25 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/01 18:40:18 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_find_next_prime(int nb);

int main(void)
{
	int nb;

	nb = 6;
	printf("%d\n", ft_find_next_prime(nb));
}
