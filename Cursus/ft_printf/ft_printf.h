/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:35:45 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/19 19:01:56 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(char *s);
void	ft_select(va_list args, const char *str, int i, int *len);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putnbr_base(int nbr, char *base);

#endif