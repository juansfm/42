/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:24:48 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/09/27 18:43:37 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_clean(t_observer *observer)
{
	int	i;

	i = -1;
	pthread_join(observer->supervisor, NULL);
	pthread_mutex_destroy(&observer->o_lock);
	while (++i < observer->philo_num)
	{
		pthread_join(observer->threads[i], NULL);
		pthread_mutex_destroy(&observer->forks[i]);
		pthread_mutex_destroy(&observer->philos[i].p_lock);
	}
}

long long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
