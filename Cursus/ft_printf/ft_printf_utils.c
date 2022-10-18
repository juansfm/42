/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:04:26 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/18 19:14:59 by jsaavedr         ###   ########.fr       */
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
		ft_putnbr(va_arg(args, int));
	if (str[i] == 'c')
		ft_putchar(va_arg(args, char));
	if (str[i] == 's')
		ft_putstr(va_arg(args, char *));
	else if (str[i] == 'p')
		ft_putnbr(va_arg(args, unsigned long long));
	if (str[i] == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	if (str[i] == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	if (str[i] == '%')
		ft_putchar('%');
}
