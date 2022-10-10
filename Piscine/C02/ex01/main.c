/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:54:46 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/24 20:39:14 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
char    *ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
	char	src[] = "Soy el coche";
	char	dest[] = "Patatas en el congelador";
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	ft_strncpy(dest, src, 15);
	i = 0;
	while (dest[i])
	{
		write(1,&dest[i],1);
		i++;
	}
}
