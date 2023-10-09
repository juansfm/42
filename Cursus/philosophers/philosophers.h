/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:23:01 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/09 19:19:44 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"
# define FORK "has taken a fork"

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"

typedef struct s_info
{
	int				philo_num;
	long long		start_time;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				meals_num;
	int				full_philos;
	int				death;
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	g_death_mutex;
	pthread_mutex_t	full_meals_mutex;
	pthread_t		supervisor;
}					t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	int				is_dead;
	int				eaten_times;
	long long		last_eat;
	struct s_info	*info;
	int				l_fork_id;
	int				r_fork_id;
	pthread_mutex_t	o_death_mutex;
	pthread_mutex_t	meals_mutex;
	pthread_mutex_t	last_eat_mutex;
}					t_philo;

long long			ft_atol(const char *str);
void				*ft_calloc(size_t count, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);

int					ft_check_data(int argc, char **argv);
int					ft_check_args(int argc);
int					ft_check_numbers(char **argv);
int					ft_check_limits(char **argv);

void				ft_init_info(t_info *info, int argc, char **argv);
void				ft_init_mutex(t_info *info);
void				ft_init_philo(t_info *info);
void				ft_init_threads(t_info *info);

void				*ft_control_routine(void *arg);
void				*ft_phi(void *arg);
void				ft_one_philo(t_philo *philo);
int					ft_control_philo(t_info *info, int i);

void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_take_forks(t_philo *philo);
void				ft_leave_forks(t_philo *philo);

long long			ft_t_eat(t_philo *philo);
long long			ft_t_die(t_philo *philo);
long long			ft_t_sleep(t_philo *philo);
long long			ft_last_eat(t_philo *philo, long long i);

int					ft_o_death(t_philo *philo, int i);
int					ft_g_death(t_philo *philo, int i);
int					ft_full_mutex(t_philo *philo, int i);
int					ft_meals_mutex(t_philo *philo, int i);

long long			ft_get_time(void);
void				ft_print_status(t_philo *philo, char *status, char *color);
void				ft_usleep(long long usleep_time);

#endif