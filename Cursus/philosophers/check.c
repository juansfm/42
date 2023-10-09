/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:50:02 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/09 16:21:28 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_data(int argc, char **argv)
{
	int	error;

	error = 0;
	error += ft_check_args(argc);
	if (!error)
		error += ft_check_numbers(argv);
	if (!error)
		error += ft_check_limits(argv);
	return (error);
}

int	ft_check_args(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	return (0);
}

int	ft_check_numbers(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error: Invalid argument\n");
				return (1);
			}
		}
		if ((i == 1 || i == 5) && ft_atol(argv[i]) == 0)
		{
			printf("Error: Invalid argument\n");
			return (1);
		}
	}
	return (0);
}

int	ft_check_limits(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < 0)
		{
			printf("Error: Argument out of range\n");
			return (1);
		}
	}
	return (0);
}
