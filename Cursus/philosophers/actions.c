/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:04:31 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/04 19:04:20 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo *philo)
{
	long long	start_time;

	start_time = -2;
	if (!ft_check_death(philo))
	{
		start_time = ft_take_forks(philo);
		philo->last_eat = ft_get_time();
		ft_print_status(philo, GREEN, EAT);
	}
	while (!ft_check_death(philo))
	{
		pthread_mutex_lock(&philo->p_lock);
		if (ft_get_time() - philo->last_eat >= philo->info->time_to_die)
		{
			philo->is_dead = 1;
			printf("Hola%lld\n", ft_get_time() - start_time);
			break ;
		}
		if (ft_get_time() - start_time >= philo->info->time_to_eat)
			break ;
		pthread_mutex_unlock(&philo->p_lock);
		usleep(10);
	}
	if (start_time != -2)
		ft_leave_forks(philo);
}

void	ft_sleep(t_philo *philo)
{
	long long	start_time;

	start_time = ft_get_time();
	ft_print_status(philo, BLUE, SLEEP);
	while (!ft_check_death(philo))
	{
		pthread_mutex_lock(&philo->p_lock);
		if (ft_get_time() - philo->last_eat >= philo->info->time_to_die)
		{
			philo->is_dead = 1;
			pthread_mutex_unlock(&philo->p_lock);
			return ;
		}
		if (ft_get_time() - start_time >= philo->info->time_to_sleep)
		{
			pthread_mutex_unlock(&philo->p_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->p_lock);
		usleep(10);
	}
}

long long	ft_take_forks(t_philo *philo)
{
	// while (1)
	// {
	// 	pthread_mutex_lock(&philo->p_lock);
	// 	if (!philo->info->forks[philo->r_fork_id].is_taken
	// 		&& !philo->info->forks[philo->l_fork_id].is_taken)
	// 	{
	// 		pthread_mutex_unlock(&philo->p_lock);
	// 		break ;
	// 	}
	// 	if (ft_check_death(philo))
	// 	{
	// 		pthread_mutex_unlock(&philo->p_lock);
	// 		return (1);
	// 	}
	// 	pthread_mutex_unlock(&philo->p_lock);
	// 	usleep(10);
	// }
	ft_take_right(philo);
	ft_take_left(philo);
	return (ft_get_time());
}

void	ft_leave_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 1 || philo->philo_id != philo->info->philo_num
		- 1)
	{
		ft_leave_right(philo);
		ft_leave_left(philo);
	}
	else if (philo->philo_id % 2 == 0
			|| philo->philo_id == philo->info->philo_num - 1)
	{
		ft_leave_left(philo);
		ft_leave_right(philo);
	}
	pthread_mutex_lock(&philo->info->mutex.print_lock);
	printf("%lld %i leaves forks\n", ft_get_time(), philo->philo_id);
	pthread_mutex_unlock(&philo->info->mutex.print_lock);
}
