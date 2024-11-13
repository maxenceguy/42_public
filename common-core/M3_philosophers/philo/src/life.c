/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:16:00 by mguy              #+#    #+#             */
/*   Updated: 2024/09/04 18:33:45 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(philo->data->value));
	philo->data->death++;
	if (philo->data->death == 1)
		i = 1;
	pthread_mutex_unlock(&(philo->data->value));
	if (i == 1)
	{
		pthread_mutex_lock(&(philo->data->value));
		philo->data->printf = false;
		pthread_mutex_unlock(&(philo->data->value));
		pthread_mutex_lock(&(philo->data->printf_mutex));
		printf("%lld %d %s\n",
			get_time() - philo->data->init_time, philo->id + 1, "died");
		pthread_mutex_unlock(&(philo->data->printf_mutex));
		pthread_mutex_lock(&(philo->data->value));
		philo->data->printf = false;
		pthread_mutex_unlock(&(philo->data->value));
	}
}

void	ft_join(t_philo *philo, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

static int	loop(t_philo *philo)
{
	int	count_meal;

	pthread_mutex_lock(&(philo->mtime));
	count_meal = philo->count_meal;
	pthread_mutex_unlock(&(philo->mtime));
	mprintf(philo, "is thinking");
	if (philo->id % 2 != 0)
	{
		my_sleep(philo, philo->t_eat / 2);
	}
	pthread_mutex_lock(&(philo->data->value));
	while (philo->data->death == 0 && (count_meal < philo->round
			|| philo->round == -1))
	{
		pthread_mutex_unlock(&(philo->data->value));
		if (eat_philo(philo))
			return (1);
		mprintf(philo, "is thinking");
		pthread_mutex_lock(&(philo->data->value));
	}
	pthread_mutex_unlock(&(philo->data->value));
	pthread_mutex_lock(&(philo->mtime));
	count_meal = philo->count_meal;
	pthread_mutex_unlock(&(philo->mtime));
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->value);
	philo->data->ready++;
	pthread_mutex_unlock(&philo->data->value);
	check_start(philo);
	pthread_mutex_lock(&philo->data->value);
	philo->init_time = philo->data->init_time;
	pthread_mutex_unlock(&philo->data->value);
	pthread_mutex_lock(&(philo->mtime));
	philo->last_meal = get_time() - philo->init_time;
	pthread_mutex_unlock(&(philo->mtime));
	loop(philo);
	return ((void *)0);
}

int	life(t_philo *philo, t_data *data)
{
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * data->nb_philo);
	if (threads == NULL)
		return (1);
	if (start_threads(threads, philo, data))
		return (free(threads), 1);
	check_death(philo, data->nb_philo);
	ft_join(philo, threads);
	free(threads);
	return (0);
}
