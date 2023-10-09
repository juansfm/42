/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_times.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:25:27 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/09 17:37:49 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_t_eat(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->info->eat_mutex);
	time = philo->info->time_to_eat;
	pthread_mutex_unlock(&philo->info->eat_mutex);
	return (time);
}

long long	ft_t_die(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->info->die_mutex);
	time = philo->info->time_to_die;
	pthread_mutex_unlock(&philo->info->die_mutex);
	return (time);
}

long long	ft_t_sleep(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->info->sleep_mutex);
	time = philo->info->time_to_sleep;
	pthread_mutex_unlock(&philo->info->sleep_mutex);
	return (time);
}

long long	ft_last_eat(t_philo *philo, long long i)
{
	long long	time;

	pthread_mutex_lock(&philo->last_eat_mutex);
	if (i > 0)
		philo->last_eat = i;
	time = philo->last_eat;
	pthread_mutex_unlock(&philo->last_eat_mutex);
	return (time);
}
