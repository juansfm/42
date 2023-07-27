/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:39:42 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/26 19:37:38 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	ft_init_philo(argv);
	return (0);
}

t_philo	*ft_init_philo(char **argv)
{
	int		num_philos;
	int		time_death;
	int		time_eat;
	int		time_sleep;
	t_philo	*philos;

	num_philos = ft_atoi(argv[1]);
	time_death = ft_atoi(argv[2]);
	time_eat = ft_atoi(argv[3]);
	time_sleep = ft_atoi(argv[4]);
	philos = malloc(sizeof(t_philo) * (num_philos + 1));
	if (!philos)
		return (NULL);
	ft_malloc_philo(philos, num_philos);
	return (philos);
}

void	ft_malloc_philo(t_philo *philos, int num_philos)
{
	int		i;

	i = -1;
	while (++i < num_philos)
	{
		philos[i].num_philo = i + 1;
		pthread_create(&philos[i].philo, NULL, ft_philo, &philos[i]);
		pthread_mutex_init(&philos[i].fork, NULL);
	}
}

void	*ft_philo(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;
	return (NULL);
}
