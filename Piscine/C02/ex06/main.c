/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:03:28 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/22 19:48:43 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char	str[] = "\n";
	int		i;
	char	j;

	i = ft_str_is_printable(str);
	j = i + '0';
	write (1, &j, 1);
}
