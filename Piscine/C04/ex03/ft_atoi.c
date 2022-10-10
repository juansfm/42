/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:35:19 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/30 22:10:33 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] < '0' || str[i] > '9')
	{
		if (str[i] == ' ' || str[i] == '+' || (str[i] > 8 && str[i] < 14))
			i++;
		else if (str[i] == '-')
		{
			sign = sign * -1;
			i++;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	num = num * sign;
	return (num);
}
