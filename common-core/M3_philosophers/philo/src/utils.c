/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:37:04 by mguy              #+#    #+#             */
/*   Updated: 2024/09/04 18:32:18 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philos_ready(t_philo *philo)
{
	bool	run;

	run = false;
	while (run == false)
	{
		usleep(10);
		pthread_mutex_lock(&philo->data->value);
		if (philo->data->ready == philo->nb_philo)
			run = true;
		pthread_mutex_unlock(&philo->data->value);
	}
	pthread_mutex_lock(&philo->data->value);
	philo->data->start = true;
	philo->data->init_time = get_time();
	pthread_mutex_unlock(&philo->data->value);
}

void	check_start(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->value));
	while (philo->data->start != true)
	{
		pthread_mutex_unlock(&(philo->data->value));
		pthread_mutex_lock(&(philo->data->value));
	}
	pthread_mutex_unlock(&(philo->data->value));
}

int	start_threads(pthread_t	*threads, t_philo *philo, t_data *data)
{
	int			i;

	philo->data->init_time = get_time();
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_create(&threads[i], NULL, routine, &philo[i]))
		{
			printf("Error: pthread_create\n");
			while (--i >= 0)
				pthread_detach(threads[i]);
			return (1);
		}
	}
	philos_ready(philo);
	return (0);
}

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * (u_int64_t)1000) + (t.tv_usec / 1000));
}

int	my_sleep(t_philo *philo, int time)
{
	long long	start;
	long long	elapsed;

	start = get_time();
	elapsed = get_time() - start;
	while (elapsed < time)
	{
		if (is_dead(philo))
			return (1);
		usleep((time - elapsed) / 2);
		elapsed = get_time() - start;
	}
	return (0);
}
