/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:23:20 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/09 18:02:08 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (ft_check_data(argc, argv))
		return (0);
	ft_init_info(&info, argc, argv);
	ft_init_mutex(&info);
	ft_init_philo(&info);
	ft_init_threads(&info);
}

void	ft_init_info(t_info *info, int argc, char **argv)
{
	info->philo_num = ft_atol(argv[1]);
	info->start_time = ft_get_time();
	info->time_to_die = ft_atol(argv[2]);
	info->time_to_eat = ft_atol(argv[3]);
	info->time_to_sleep = ft_atol(argv[4]);
	if (argc == 5)
		info->meals_num = -1;
	else
		info->meals_num = ft_atol(argv[5]);
	info->full_philos = 0;
	info->death = 0;
	info->philo = ft_calloc(info->philo_num, sizeof(t_philo));
	info->forks = ft_calloc(info->philo_num, sizeof(pthread_mutex_t));
}

void	ft_init_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		pthread_mutex_init(&info->philo[i].o_death_mutex, NULL);
		pthread_mutex_init(&info->philo[i].meals_mutex, NULL);
		pthread_mutex_init(&info->philo[i].last_eat_mutex, NULL);
	}
	pthread_mutex_init(&info->print_mutex, NULL);
	pthread_mutex_init(&info->eat_mutex, NULL);
	pthread_mutex_init(&info->die_mutex, NULL);
	pthread_mutex_init(&info->sleep_mutex, NULL);
	pthread_mutex_init(&info->g_death_mutex, NULL);
	pthread_mutex_init(&info->full_meals_mutex, NULL);
}

void	ft_init_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
	{
		info->philo[i].philo_id = i + 1;
		info->philo[i].is_dead = 0;
		info->philo[i].last_eat = info->start_time;
		info->philo[i].info = info;
		if (info->meals_num == -1)
			info->philo[i].eaten_times = -1;
		else
			info->philo[i].eaten_times = 0;
		if (i == 0)
			info->philo[i].r_fork_id = info->philo_num - 1;
		else
			info->philo[i].r_fork_id = i - 1;
		info->philo[i].l_fork_id = i;
	}
}

void	ft_init_threads(t_info *info)
{
	int	i;

	pthread_create(&info->supervisor, NULL, ft_control_routine, info);
	i = -1;
	while (++i < info->philo_num)
		pthread_create(&info->philo[i].thread, NULL, ft_phi, &info->philo[i]);
	i = info->philo_num;
	while (--i >= 0)
	{
		pthread_join(info->philo[i].thread, NULL);
		pthread_mutex_destroy(&info->forks[i]);
		pthread_mutex_destroy(&info->philo[i].o_death_mutex);
		pthread_mutex_destroy(&info->philo[i].meals_mutex);
	}
	pthread_join(info->supervisor, NULL);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->die_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->sleep_mutex);
	pthread_mutex_destroy(&info->g_death_mutex);
	pthread_mutex_destroy(&info->full_meals_mutex);
	free(info->philo);
	free(info->forks);
}
