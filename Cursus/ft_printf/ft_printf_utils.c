/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:04:26 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/16 17:19:34 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_select(va_list args, const char *str, int i)
{
	if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr((int)va_arg(args, int));
	else if (str[i] == 'c')
		ft_putchar((char)va_arg(args, char));
	else if (str[i] == 's')
		ft_putstr((char *)va_arg(args, (char *)));
	else if (str[i] == 'p')
		ft_putnbr((unsigned long long)va_arg(args, unsigned long long));
	else if (str[i] == 'x')
		ft_putnbr_base((int)va_arg(args, int), "0123456789abcdef");
	else if (str[i] == 'X')
		ft_putnbr_base((int)va_arg(args, int), "0123456789ABCDEF");
	else if (str[i] == '%')
		ft_putchar('%');
}
