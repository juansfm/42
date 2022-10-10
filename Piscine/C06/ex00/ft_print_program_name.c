/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:54:46 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/31 19:10:18 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argc;
	while (argv[0][i] != '\0')
	{
		ft_putchar(argv[0][i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
