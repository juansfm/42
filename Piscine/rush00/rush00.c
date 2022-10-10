/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgalvez- <pgalvez-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:29:04 by pgalvez-          #+#    #+#             */
/*   Updated: 2022/08/16 10:45:52 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(char a, char b, char c, int x)
{
	int	contx;

	contx = 2;
	ft_putchar(a);
	while (contx < (x))
	{
		ft_putchar(b);
		contx++;
	}
	if (contx > 2)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	conty;

	conty = 1;
	if (x < 0 || y < 0)
		return ;
	while (conty <= y)
	{
		if (conty == 1)
			print_line('/', '*', '\\', x);
		else if (conty == (y))
			print_line('\\', '*', '/', x);
		else
			print_line('*', ' ', '*', x);
		conty++;
	}
}
