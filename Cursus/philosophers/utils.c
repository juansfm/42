/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:24:48 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/04 18:28:44 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_print_status(t_philo *philo, char *color, char *status)
{
	long long	time;

	time = ft_get_time() - philo->info->time_start;
	pthread_mutex_lock(&philo->info->mutex.print_lock);
	printf("%s%lld %d %s%s\n", color, time, philo->philo_id, status, RESET);
	pthread_mutex_unlock(&philo->info->mutex.print_lock);
}

void	ft_clean(t_observer info)
{
	int	i;

	i = -1;
	while (++i < info.philo_num)
	{
		pthread_mutex_destroy(&info.philos[i].p_lock);
		pthread_mutex_destroy(&info.forks[i].f_lock);
		pthread_join(info.philos[i].thread, NULL);
	}
	pthread_join(info.supervisor, NULL);
}
