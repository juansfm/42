/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:39:42 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/29 15:09:06 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (1);
	if (ft_check_args(argv))
		return (1);
	i = -1;
	ft_init_philo(argv);
	return (0);
}

t_philo	*ft_init_philo(char **argv)
{
	int			num_philos;
	t_philo		*philos;
	
	printf("Paco");
	num_philos = ft_atoi(argv[1]);
	philos = malloc(sizeof(t_philo) * (num_philos + 1));
	if (!philos)
		return (NULL);
	ft_malloc_philo(philos, num_philos);
	return (philos);
}

void	ft_malloc_philo(t_philo *philos, int num_philos)
{
	int	i;

	i = -1;
	while (++i < num_philos)
	{
		philos[i].num_philo = i + 1;
		pthread_create(&philos[i].philo, NULL, ft_philo, &philos[i]);
		pthread_mutex_init(&philos[i].fork, NULL);
	}
}

int	ft_check_args(char **argv)
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
				return (1);
		}
	}
	return (0);
}
