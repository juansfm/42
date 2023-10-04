/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:39 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/04 19:08:51 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_supervisor(void *arg)
{
	int			i;
	t_observer	observer;
	int			dead_philo;

	observer = *(t_observer *)arg;
	usleep(observer.time_to_die * 1000);
	while (1)
	{
		i = -1;
		while (++i < observer.philo_num && &observer.philos[i])
		{
			dead_philo = ft_dead_philo(&observer.philos[i], -1);
			if (dead_philo)
			{
				pthread_mutex_unlock(&observer.philos[i].p_lock);
				observer.dead_philo = 1;
				ft_print_status(&observer.philos[i], RED, DEAD);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	*ft_philo(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;
	if (philo.info->philo_num == 1)
	{
		ft_one_philo(&philo);
		return (NULL);
	}
	// if (philo.philo_id % 2 == 0 || philo.philo_id == philo.info->philo_num)
	// {
	// 	ft_print_status(&philo, PURPLE, THINK);
	// 	usleep(10);
	// }
	while (philo.info->dead_philo == 0)
	{
		ft_eat(&philo);
		if (ft_check_death(&philo))
			break ;
		ft_sleep(&philo);
		if (ft_check_death(&philo))
			break ;
		printf("someone died?%i \n", philo.info->dead_philo);
		ft_print_status(&philo, PURPLE, THINK);
	}
	printf("Someone died\n");
	return (NULL);
}

void	ft_one_philo(t_philo *philo)
{
	ft_print_status(philo, YELLOW, FORK);
	usleep(philo->info->time_to_die * 1000);
	ft_print_status(philo, RED, DEAD);
	return ;
}

int	ft_check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_lock);
	if (philo->info->dead_philo)
	{
		pthread_mutex_unlock(&philo->p_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->p_lock);
	return (0);
}
