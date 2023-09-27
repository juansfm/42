/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:04:31 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/09/27 18:40:56 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo philo)
{
	long long	start_time;

	start_time = ft_take_forks(philo);
	philo.is_eating = 1;
	printf("%s%lld %d %s%s\n", GREEN, ft_get_time(), philo.philo_id, EAT, RESET);
	while (1)
	{
		if (ft_get_time() - start_time >= philo.info->time_to_eat)
		{
			ft_leave_forks(philo);
			return ;
		}
		usleep(10);
	}
}

void	ft_sleep(t_philo philo)
{
	long long	start_time;

	start_time = ft_get_time();
	printf("%s%lld %d %s%s\n", BLUE, ft_get_time(), philo.philo_id, SLEEP, RESET);
	while (1)
	{
		pthread_mutex_lock(&philo.p_lock);
		if (ft_get_time() - start_time >= philo.info->time_to_sleep)
		{
			pthread_mutex_unlock(&philo.p_lock);
			break ;
		}
		pthread_mutex_unlock(&philo.p_lock);
		usleep(10);
	}
}

int	ft_death(t_philo philo)
{
	pthread_mutex_lock(&philo.info->o_lock);
	if (philo.info->dead_philo)
	{
		pthread_mutex_unlock(&philo.info->o_lock);
		return (1);
	}
	return (0);
}

long long	ft_take_forks(t_philo philo)
{
	pthread_mutex_lock(&philo.info->o_lock);
	if (philo.philo_id % 2 == 0 || philo.philo_id != philo.info->philo_num - 1)
	{
		if (philo.philo_id == 1)
			pthread_mutex_lock(&philo.info->forks[philo.info->philo_num - 1]);
		else
			pthread_mutex_lock(&philo.info->forks[philo.philo_id - 2]);
		printf("%s%lld %d %s%s\n", YELLOW, ft_get_time(), philo.philo_id, FORK, RESET);
		pthread_mutex_lock(&philo.info->forks[philo.philo_id - 1]);
		printf("%s%lld %d %s%s\n", YELLOW, ft_get_time(), philo.philo_id, FORK, RESET);
	}
	else if (philo.philo_id % 2 == 1 || philo.philo_id == philo.info->philo_num
		- 1)
	{
		pthread_mutex_lock(&philo.info->forks[philo.philo_id - 1]);
		printf("%lld %d %s\n", ft_get_time(), philo.philo_id, FORK);
		if (philo.philo_id == 1)
			pthread_mutex_lock(&philo.info->forks[philo.info->philo_num - 1]);
		else
			pthread_mutex_lock(&philo.info->forks[philo.philo_id - 2]);
		printf("%lld %d %s\n", ft_get_time(), philo.philo_id, FORK);
	}
	pthread_mutex_unlock(&philo.info->o_lock);
	philo.last_eat = ft_get_time();
	return (ft_get_time());
}

void	ft_leave_forks(t_philo philo)
{
	pthread_mutex_lock(&philo.p_lock);
	philo.is_eating = 0;
	pthread_mutex_unlock(&philo.p_lock);
	philo.last_eat = ft_get_time();
	if (philo.philo_id == 1)
		pthread_mutex_unlock(&philo.info->forks[philo.info->philo_num - 1]);
	else
		pthread_mutex_unlock(&philo.info->forks[philo.philo_id - 2]);
	pthread_mutex_unlock(&philo.info->forks[philo.philo_id - 1]);
	printf("%lld %i leaves forks\n", ft_get_time(), philo.philo_id);
}
