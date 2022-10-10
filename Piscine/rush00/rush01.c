/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:56:18 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/14 12:08:38 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_lines(int a, int b, int c, int d);

void	rush(int x, int y)
{
	int	contx;
	int	conty;

	contx = 1;
	conty = 1;
	while (conty <= y)
	{
		print_lines(conty, contx, y, x);
		conty = conty +1;
	}
}

void	print_lines(int a, int b, int c, int d)
{
	while (b <= d)
	{
		if ((a == 1) || (a == c))
		{
			if (((b == 1) && (a == 1)) || (((b == d) && (a == c)) && (a != 1)))
				ft_putchar('/');
			else if (((b == 1) && (a == c)) || ((b == d) && (a == 1)))
			{
				if ((a != 1) || (b != 1))
					ft_putchar('\\');
			}
			else if ((b > 1) && (b < d))
				ft_putchar('*');
		}
		if ((a > 1) && (a < c))
		{
			if ((b == 1) || (b == d))
				ft_putchar('*');
			else if ((b > 1) && (b < d))
				ft_putchar(' ');
		}
		b = b +1;
		if (b == d +1)
			ft_putchar('\n');
	}
}
