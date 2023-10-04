/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:04:51 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/04 19:08:32 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_dead_philo(t_philo *philo, int i)
{
	int	dead_philo;

	pthread_mutex_lock(&philo->d_lock);
	if (i == -1)
		dead_philo = philo->is_dead;
	else
	{
		philo->is_dead = i;
		dead_philo = i;
	}
	pthread_mutex_unlock(&philo->d_lock);
	return (dead_philo);
}
