/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:48:43 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/24 19:39:10 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
char	*ft_strcpy(char *dest, char *src);

int main(void)
{
	char	src[] = "bolo";
	char	dest[] = "Patata";
	unsigned int 	i;

	i = 0;
	ft_strcpy(dest, src);
	while (dest[i] != '\0')
	{
		write(1,&dest[i],1);
		i++;
	}
}
