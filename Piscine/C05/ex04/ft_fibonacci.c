/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:32:29 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/09/01 17:08:43 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	result;

	if (index < 0)
		result = -1;
	else if (index == 0)
		result = 0;
	else if (index == 1)
		result = 1;
	else
		result = ft_fibonacci(index -1) + ft_fibonacci(index -2);
	return (result);
}
