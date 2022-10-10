/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:01:58 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/31 16:09:52 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_base(int nbr, char *base);
int	main(void)
{
	int nbr;
	char base[] = "OdioAN0rmIneTtE";

	nbr = -455;
	ft_putnbr_base(nbr, base);
}
