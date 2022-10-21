/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:15:00 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/10/21 12:19:17 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int unbr, int *len)
{
	if (unbr > 9)
	{
		ft_putunbr(unbr / 10, len);
	}
	ft_putchar('0' + unbr % 10, len);
}
