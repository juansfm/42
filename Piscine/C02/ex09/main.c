/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:03:28 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/25 16:38:03 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	str[] = "soY El cochE-robOt 39k";
	int	i;
	
	i = 0;
	ft_strcapitalize(str);
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}
