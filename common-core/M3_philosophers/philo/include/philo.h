/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:18:34 by mguy              #+#    #+#             */
/*   Updated: 2024/08/29 17:26:30 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_data
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				round;
	long long		init_time;
	int				death;
	int				ready;
	bool			start;
	bool			printf;
	pthread_t		tprintf;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	value;
}	t_data;

typedef struct s_fork
{
	size_t			taked;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philo
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				round;
	long long		init_time;

	int				id;
	long long		last_meal;
	int				eating;
	int				count_meal;
	int				r_hand;
	int				l_hand;
	long long		die_time;
	t_data			*data;
	t_fork			*r_fork;
	t_fork			*l_fork;
	pthread_t		thread;
	pthread_mutex_t	mtime;
	pthread_mutex_t	mstart;

}	t_philo;

int			ft_atoi(const char *str);
int			check_params(int ac, char **av);
int			init(int ac, char **av, t_data *data);
int			init_philo(t_philo **philo, t_fork **fork, t_data *data);
int			life(t_philo *philo, t_data *data);
long long	get_time(void);
// int			take_forks(t_philo *philo);
int			eat_philo(t_philo *philo);
void		put_forks(t_philo *philo);
int			sleep_philo(t_philo *philo);
void		philo_think(t_philo *philo);
void		mprintf(t_philo *philo, char *s);
void		check_death(t_philo *philo, int nb_philo);
void		end(t_philo *philo);
void		check_start(t_philo *philo);
void		*routine(void *arg);
int			start_threads(pthread_t	*threads, t_philo *philo, t_data *data);
int			is_dead(t_philo *philo);
int			right_fork(t_philo *philo);
int			left_fork(t_philo *philo);
int			my_sleep(t_philo *philo, int time);
void		destroy_mutex(t_philo *philo, int i);
int			init_mutex(t_philo *philo);
int			error_init(t_philo **philo, t_data *data, int i);

#endif
