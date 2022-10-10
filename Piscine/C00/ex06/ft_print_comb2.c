/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 22:08:52 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/15 14:38:19 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_lines(char a, char b, char c, char d);
void	second_number(char a, char b);

void	ft_print_comb2(void)

{
	char	a;
	char	b;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			second_number(a, b);
			b++;
		}
		a = a +1;
	}
}

void	print_lines(char a, char b, char c, char d)

{
	if (c != '0' || d != '1')
		write (1, &", ", 2);
	write (1, &a, 1);
	write (1, &b, 1);
	write (1, &" ", 1);
	write (1, &c, 1);
	write (1, &d, 1);
}

void	second_number(char a, char b)
{
	char	c;
	char	d;

	c = a;
	while (c <= '9')
	{
		d = '0';
		if (c == a)
			d = b +1;
		while (d <= '9')
		{
			print_lines(a, b, c, d);
			d++;
		}
		c++;
	}
}
