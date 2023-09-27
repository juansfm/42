/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:39:42 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/09/27 18:14:53 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_observer	*observer;

	if (ft_check(argc, argv))
		return (1);
	observer = ft_calloc(1, sizeof(t_observer));
	ft_init_var(argc, argv, observer);
	ft_init_forks(observer);
	// pthread_create(&observer->supervisor, NULL, ft_supervisor, observer);
	ft_init_philos(observer->philos);
	return (0);
}

void	ft_init_var(int argc, char **argv, t_observer *observer)
{
	observer->philo_num = ft_atoi(argv[1]);
	observer->time_start = ft_get_time();
	observer->time_to_die = ft_atoi(argv[2]);
	observer->time_to_eat = ft_atoi(argv[3]);
	observer->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		observer->meals_num = ft_atoi(argv[5]);
	else
		observer->meals_num = -1;
	observer->eaten_philos = 0;
	observer->dead_philo = 0;
	pthread_mutex_init(&observer->o_lock, NULL);
	observer->philos = ft_calloc(observer->philo_num, sizeof(t_philo));
	observer->philos[0].info = observer;
	observer->threads = ft_calloc(observer->philo_num, sizeof(pthread_t));
}

void	ft_init_philos(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].info->philo_num)
	{
		pthread_mutex_init(&philos[i].p_lock, NULL);
		pthread_mutex_lock(&philos[i].p_lock);
		philos[i].info = philos[0].info;
		philos[i].philo_id = i + 1;
		philos[i].is_dead = 0;
		philos[i].is_eating = 0;
		philos[i].last_eat = philos[i].info->time_start;
		if (philos[i].info->meals_num != -1)
			philos[i].num_eat = 0;
		else
			philos[i].num_eat = -1;
		pthread_mutex_unlock(&philos[i].p_lock);
	}
	i = -1;
	pthread_mutex_lock(&philos[0].info->o_lock);
	while (++i < philos[0].info->philo_num)
		pthread_create(&philos[i].info->threads[i], NULL, ft_philo, &philos[i]);
	pthread_mutex_unlock(&philos[0].info->o_lock);
}

void	ft_init_forks(t_observer *observer)
{
	int	i;

	i = -1;
	observer->forks = ft_calloc(observer->philo_num, sizeof(pthread_mutex_t));
	while (++i < observer->philo_num)
		pthread_mutex_init(&observer->forks[i], NULL);
}
