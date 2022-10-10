/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:03:28 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/22 11:22:53 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	char	str[] = "Soyelcaballerodelanoche";
	int		i;
	char	j;

	i = ft_str_is_alpha(str);
	j = i + '0';
	write (1, &j, 1);
}
