/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:39:39 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/10/04 19:09:53 by jsaavedr         ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t		f_lock;
	int					is_taken;
}						t_fork;

typedef struct s_mutex
{
	pthread_mutex_t	t_eat_lock;
	pthread_mutex_t	t_sleep_lock;
	pthread_mutex_t	t_death_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	print_lock;
}				t_mutex;
typedef struct s_observer
{
	int					philo_num;
	long long			time_start;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals_num;
	int					eaten_philos;
	int					dead_philo;
	struct s_philo		*philos;
	pthread_t			supervisor;
	struct s_fork		*forks;
	struct s_mutex		mutex;
}						t_observer;

typedef struct s_philo
{
	int					philo_id;
	pthread_t			thread;
	int					is_dead;
	long long			last_eat;
	int					num_eat;
	int					r_fork_id;
	int					l_fork_id;
	struct s_observer	*info;
	pthread_mutex_t		p_lock;
	pthread_mutex_t		d_lock;
}						t_philo;

//LIBFT
long					ft_atol(const char *str);
void					*ft_calloc(size_t count, size_t size);

int						ft_check(int argc, char **argv);
int						ft_check_args(int argc);
int						ft_check_numbers(char **argv);
int						ft_check_limits(char **argv);

void					ft_init_var(int argc, char **argv,
							t_observer *observer);
void					ft_init_philos(t_observer *info);
void					ft_init_mutex(t_observer *observer);

void					*ft_philo(void *arg);
void					*ft_supervisor(void *arg);
void					ft_one_philo(t_philo *philo);

void					ft_eat(t_philo *philo);
void					ft_sleep(t_philo *philo);
int						ft_check_death(t_philo *philo);
long long				ft_take_forks(t_philo *philo);
void					ft_leave_forks(t_philo *philo);

int						ft_take_right(t_philo *philo);
int						ft_take_left(t_philo *philo);
void					ft_leave_right(t_philo *philo);
void					ft_leave_left(t_philo *philo);

int						ft_dead_philo(t_philo *philo, int dead_philo);

long long				ft_get_time(void);
void					ft_print_status(t_philo *philo, char *color,
							char *status);
void					ft_clean(t_observer info);
#endif