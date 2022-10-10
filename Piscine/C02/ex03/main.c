/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:23:31 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/22 12:33:08 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	str[] = "";
	int i;
	int j;

	i = ft_str_is_numeric(str);
	j = i + '0';
	write (1, &j, 1);
}
