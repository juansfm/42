/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:39 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/28 14:20:36 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philo(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;

	return (NULL);
}

void	*ft_observer(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;
	return (NULL);
}
