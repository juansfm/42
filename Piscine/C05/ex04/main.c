/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:36:51 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/01 17:08:36 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_fibonacci(int index);
int main(void)
{
	int index;

	index = -10000;
	printf("%d\n", ft_fibonacci(index));
	return (0);
}
