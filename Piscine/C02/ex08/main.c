/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:03:28 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/22 20:48:55 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	str[] = "SoY El cAbAlLeRo dE La nOcHe";
	int	i;
	
	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}
