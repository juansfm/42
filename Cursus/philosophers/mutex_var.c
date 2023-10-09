/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:46:00 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/08 20:08:42 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_g_death(t_philo *philo, int i)
{
	int	death;

	pthread_mutex_lock(&philo->info->g_death_mutex);
	if (i == 1)
		philo->info->death = 1;
	death = philo->info->death;
	pthread_mutex_unlock(&philo->info->g_death_mutex);
	return (death);
}

int	ft_o_death(t_philo *philo, int i)
{
	int	death;

	pthread_mutex_lock(&philo->o_death_mutex);
	if (i == 1)
		philo->is_dead = 1;
	death = philo->is_dead;
	pthread_mutex_unlock(&philo->o_death_mutex);
	return (death);
}

int	ft_meals_mutex(t_philo *philo, int i)
{
	int	meals;

	pthread_mutex_lock(&philo->meals_mutex);
	meals = philo->eaten_times;
	if (i == -1)
		philo->eaten_times = -1;
	else if (i == 1 && philo->eaten_times != -1)
		philo->eaten_times++;
	pthread_mutex_unlock(&philo->meals_mutex);
	return (meals);
}

int	ft_full_mutex(t_philo *philo, int i)
{
	int	full_philos;

	pthread_mutex_lock(&philo->info->full_meals_mutex);
	if (i == 1)
		philo->info->full_philos++;
	full_philos = philo->info->full_philos;
	pthread_mutex_unlock(&philo->info->full_meals_mutex);
	return (full_philos);
}
