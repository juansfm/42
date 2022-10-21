/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:04:26 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/21 18:10:52 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_select(va_list args, const char *str, int i, int *len)
{
	if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (str[i] == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (str[i] == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (str[i] == 'p')
	{
		ft_putstr("0x", len);
		ft_putnbr_ba(va_arg(args, unsigned long long), "0123456789abcdef", len);
	}
	else if (str[i] == 'x')
		ft_putnbr_ba(va_arg(args, unsigned int), "0123456789abcdef", len);
	else if (str[i] == 'X')
		ft_putnbr_ba(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	else if (str[i] == 'u')
		ft_putunbr(va_arg(args, unsigned int), len);
	else if (str[i] == '%')
		ft_putchar('%', len);
}
