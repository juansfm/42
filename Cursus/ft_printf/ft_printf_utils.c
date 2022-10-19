/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:04:26 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/19 19:04:42 by jsaavedr         ###   ########.fr       */
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
	char	*s;

	if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(args, int));
	else if (str[i] == 'c')
		ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
	{
		s = va_arg(args, char *);
		ft_putstr(s);
	}
	else if (str[i] == 'p')
		ft_putnbr(va_arg(args, unsigned long long));
	else if (str[i] == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (str[i] == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (str[i] == 'u')
		ft_putnbr(va_arg(args, unsigned int));
	else if (str[i] == '%')
		ft_putchar('%');
	if (str[i] == 's')
		*len = *len + ft_strlen(s);
	else
		*len = *len + 1;
}
