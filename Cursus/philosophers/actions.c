/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:57:54 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/09 19:17:22 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo *philo)
{
	ft_take_forks(philo);
	if (ft_get_time() - ft_last_eat(philo, 0) >= ft_t_die(philo))
	{
		ft_o_death(philo, 1);
		return ;
	}
	ft_last_eat(philo, ft_get_time());
	ft_print_status(philo, EAT, GREEN);
	if (ft_meals_mutex(philo, 0) != -1)
		ft_meals_mutex(philo, 1);
	while (1)
	{
		if (ft_get_time() - ft_last_eat(philo, 0) >= ft_t_die(philo))
		{
			ft_o_death(philo, 1);
			break ;
		}
		if (ft_get_time() - ft_last_eat(philo, 0) >= ft_t_eat(philo))
			break ;
		if (ft_g_death(philo, 0))
			break ;
		ft_usleep(10);
	}
	ft_leave_forks(philo);
}

void	ft_sleep(t_philo *philo)
{
	long long	start_time;

	start_time = ft_get_time();
	if (ft_g_death(philo, 0))
		return ;
	ft_print_status(philo, SLEEP, BLUE);
	while (1)
	{
		if (ft_get_time() - ft_last_eat(philo, 0) >= ft_t_die(philo))
		{
			ft_o_death(philo, 1);
			return ;
		}
		if (ft_get_time() - start_time >= ft_t_sleep(philo))
			return ;
		if (ft_g_death(philo, 0))
			break ;
		ft_usleep(10);
	}
}

void	ft_take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0
		&& ft_last_eat(philo, 0) == philo->info->start_time)
	{
		ft_print_status(philo, THINK, BLUE);
		ft_usleep(10000);
	}
	if (ft_get_time() - ft_last_eat(philo, 0) >= ft_t_die(philo))
	{
		ft_o_death(philo, 1);
		return ;
	}
	pthread_mutex_lock(&philo->info->forks[philo->l_fork_id]);
	ft_print_status(philo, FORK, YELLOW);
	pthread_mutex_lock(&philo->info->forks[philo->r_fork_id]);
	ft_print_status(philo, FORK, YELLOW);
	return ;
}

void	ft_leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->l_fork_id]);
	pthread_mutex_unlock(&philo->info->forks[philo->r_fork_id]);
}
