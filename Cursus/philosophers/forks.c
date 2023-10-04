/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:22:33 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/03 18:21:24 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_take_right(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_lock);
	pthread_mutex_lock(&philo->info->forks[philo->r_fork_id].f_lock);
	philo->info->forks[philo->r_fork_id].is_taken = 1;
	ft_print_status(philo, YELLOW, FORK);
	pthread_mutex_unlock(&philo->p_lock);
	return (0);
}

int	ft_take_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->l_fork_id].f_lock);
	philo->info->forks[philo->l_fork_id].is_taken = 1;
	ft_print_status(philo, YELLOW, FORK);
	pthread_mutex_unlock(&philo->p_lock);
	return (0);
}

void	ft_leave_right(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_lock);
	pthread_mutex_unlock(&philo->info->forks[philo->r_fork_id].f_lock);
	philo->info->forks[philo->r_fork_id].is_taken = 0;
	pthread_mutex_unlock(&philo->p_lock);
}

void	ft_leave_left(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->l_fork_id].f_lock);
	philo->info->forks[philo->l_fork_id].is_taken = 0;
	pthread_mutex_unlock(&philo->p_lock);
}
