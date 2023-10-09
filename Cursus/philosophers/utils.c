/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:46:25 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/09 18:57:30 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_print_status(t_philo *philo, char *status, char *color)
{
	long long	time;

	if (ft_g_death(philo, 0) && ft_strncmp(status, DEAD, ft_strlen(status)))
		return ;
	pthread_mutex_lock(&philo->info->print_mutex);
	time = ft_get_time() - philo->info->start_time;
	printf("%s%lld %i %s%s\n", color, time, philo->philo_id, status, RESET);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	ft_usleep(long long usleep_time)
{
	long long	time;

	time = ft_get_time() * 1000;
	while ((ft_get_time() * 1000) - time < usleep_time)
		usleep(1);
}
