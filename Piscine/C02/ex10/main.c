/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:46:40 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/25 13:46:21 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size);

int main(void)
{
	char	src[] = "Soy el coche";
	char	dest[] = "Patatas en el congelador";
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = ft_strlcpy(dest, src, i);
	i = 0;
	while (dest[i] != '\0')
	{
		write(1,&dest[i],1);
		i++;
	}
	printf("%d\n", j);
}

