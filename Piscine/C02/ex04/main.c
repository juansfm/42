/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:33:21 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/22 19:29:43 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_str_is_lowercase(char *str);

int main(void)
{
	char	str[] = "Hola";
	int	i;
	int	j;

	i = ft_str_is_lowercase(str);
	j = i +'0';
	write (1, &j, 4);
}
