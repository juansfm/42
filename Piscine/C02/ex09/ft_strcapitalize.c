/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:48:43 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/25 17:29:18 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - ' ';
	i = 0;
	while (str[i +1] != '\0')
	{
		if (str[i +1] >= 'a' && str[i +1] <= 'z')
		{
			if ((str[i] < 97 || str[i] > 122) && (str[i] < 65 || str[i] > 90))
			{
				if (str[i] < '0' || str[i] > '9')
					str[i +1] = str[i +1] -32;
			}
		}
		if (str[i +1] >= 'A' && str[i +1] <= 'Z')
		{
			if ((str[i] > 96 && str[i] < 123) || (str[i] > 64 && str[i] < 91)
				|| (str[i] >= '0' && str[i] <= '9'))
					str[i +1] = str[i +1] +32;
		}
		i++;
	}
	return (str);
}
