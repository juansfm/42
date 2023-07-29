/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:39:39 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/28 12:47:06 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	fork;
	int				num_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
}	t_philo;

//LIBFT
int		ft_atoi(const char *str);

t_philo	*ft_init_philo(char **argv);
void	ft_malloc_philo(t_philo *philo, int num_philo);
int		ft_check_args(char **argv);

void	*ft_philo(void *arg);
void	*ft_observer(void *arg);

#endif