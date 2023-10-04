/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:39:42 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/04 18:33:12 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_observer	observer;

	if (ft_check(argc, argv))
		return (1);
	ft_init_var(argc, argv, &observer);
	ft_init_mutex(&observer);
	pthread_create(&observer.supervisor, NULL, ft_supervisor, &observer);
	ft_init_philos(&observer);
	ft_clean(observer);
	return (0);
}

void	ft_init_var(int argc, char **argv, t_observer *observer)
{
	observer->philo_num = ft_atol(argv[1]);
	observer->time_start = ft_get_time();
	observer->time_to_die = ft_atol(argv[2]);
	observer->time_to_eat = ft_atol(argv[3]);
	observer->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		observer->meals_num = ft_atol(argv[5]);
	else
		observer->meals_num = -1;
	observer->eaten_philos = 0;
	observer->dead_philo = 0;
	observer->philos = ft_calloc(observer->philo_num, sizeof(t_philo));
}

void	ft_init_philos(t_observer *in)
{
	int	i;

	i = -1;
	while (++i < in->philo_num)
	{
		pthread_mutex_init(&in->philos[i].p_lock, NULL);
		pthread_mutex_init(&in->philos[i].d_lock, NULL);
		in->philos[i].info = in;
		in->philos[i].philo_id = i + 1;
		pthread_mutex_lock(&in->philos[i].d_lock);
		in->philos[i].is_dead = 0;
		pthread_mutex_unlock(&in->philos[i].d_lock);
		in->philos[i].last_eat = in->time_start;
		if (in->meals_num != -1)
			in->philos[i].num_eat = 0;
		else
			in->philos[i].num_eat = -1;
		in->philos[i].r_fork_id = in->philos[i].philo_id - 1;
		if (in->philos[i].philo_id == 1)
			in->philos[i].l_fork_id = in->philo_num - 1;
		else
			in->philos[i].l_fork_id = in->philos[i].philo_id - 2;
	}
	i = -1;
	while (++i < in->philo_num)
	{
		pthread_create(&in->philos[i].thread, NULL, ft_philo, &in->philos[i]);
		usleep(1);
	}
}

void	ft_init_mutex(t_observer *observer)
{
	int	i;

	i = -1;
	observer->forks = ft_calloc(observer->philo_num, sizeof(t_fork));
	while (++i < observer->philo_num)
	{
		pthread_mutex_init(&observer->forks[i].f_lock, NULL);
		observer->forks[i].is_taken = 0;
	}
	pthread_mutex_init(&observer->mutex.t_eat_lock, NULL);
	pthread_mutex_init(&observer->mutex.t_sleep_lock, NULL);
	pthread_mutex_init(&observer->mutex.t_death_lock, NULL);
	pthread_mutex_init(&observer->mutex.death_lock, NULL);
	pthread_mutex_init(&observer->mutex.print_lock, NULL);
}
