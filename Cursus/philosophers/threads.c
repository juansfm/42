/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:39 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/09/27 18:26:18 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_supervisor(void *arg)
{
	int			i;
	t_observer	*observer;

	observer = (t_observer *)arg;
	printf("observador\n");
	pthread_mutex_lock(&observer->o_lock);
	usleep(10 * observer->philo_num);
	pthread_mutex_unlock(&observer->o_lock);
	while (1)
	{
		pthread_mutex_lock(&observer->o_lock);
		i = -1;
		while (++i < observer->philo_num)
		{
			pthread_mutex_lock(&observer->philos[i].p_lock);
			if (observer->philos[i].is_dead)
			{
				observer->dead_philo = 1;
				pthread_mutex_unlock(&observer->o_lock);
				pthread_mutex_unlock(&observer->philos[i].p_lock);
				ft_clean(observer);
				return (NULL);
			}
			pthread_mutex_unlock(&observer->philos[i].p_lock);
		}
		pthread_mutex_unlock(&observer->o_lock);
	}
	return (NULL);
}

void	*ft_philo(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		printf("%s%lld %d %s%s\n", PURPLE, ft_get_time(), philo.philo_id, THINK, RESET);
	}
	printf("Someone died\n");
	return (NULL);
}
