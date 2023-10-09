/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:42:28 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/09 19:22:14 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_control_routine(void *arg)
{
	t_info	*info;
	int		i;

	info = (t_info *)arg;
	while (1)
	{
		i = -1;
		while (++i < info->philo_num)
		{
			if (ft_control_philo(info, i))
				return (NULL);
		}
		if (ft_full_mutex(&info->philo[0], 0) == info->philo_num)
			return (NULL);
		ft_usleep(100);
	}
	return (NULL);
}

void	*ft_phi(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->info->philo_num == 1)
	{
		ft_one_philo(philo);
		return (NULL);
	}
	while (1)
	{
		ft_eat(philo);
		if (ft_g_death(philo, 0) || ft_full_mutex(philo,
				0) == philo->info->philo_num)
			break ;
		ft_sleep(philo);
		if (ft_g_death(philo, 0) || ft_full_mutex(philo,
				0) == philo->info->philo_num)
			break ;
		ft_print_status(philo, THINK, PURPLE);
	}
	return (NULL);
}

void	ft_one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[0]);
	ft_print_status(philo, FORK, YELLOW);
	ft_usleep(philo->info->time_to_die * 1000);
	ft_o_death(philo, 1);
	pthread_mutex_unlock(&philo->info->forks[0]);
}

int	ft_control_philo(t_info *info, int i)
{
	if (ft_get_time() - ft_last_eat(&info->philo[i],
			0) >= ft_t_die(&info->philo[i]))
	{
		ft_o_death(&info->philo[i], 1);
		ft_g_death(&info->philo[i], 1);
	}
	if (ft_g_death(&info->philo[i], 0))
	{
		ft_print_status(&info->philo[i], DEAD, RED);
		return (1);
	}
	if (ft_meals_mutex(&info->philo[i], 0) >= info->meals_num
		&& info->meals_num != -1)
	{
		ft_full_mutex(&info->philo[i], 1);
		ft_meals_mutex(&info->philo[i], -1);
	}
	return (0);
}
