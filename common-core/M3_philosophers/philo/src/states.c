/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:39:22 by mguy              #+#    #+#             */
/*   Updated: 2024/09/04 17:20:16 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	lock_forks(t_philo *philo)
{
	if (right_fork(philo))
		return (1);
	if (philo->nb_philo == 1)
	{
		my_sleep(philo, philo->t_die * 1000);
		return (1);
	}
	if (left_fork(philo))
		return (1);
	return (0);
}

static int	take_forks(t_philo *philo)
{
	if (lock_forks(philo))
		return (1);
	pthread_mutex_lock(&(philo->data->value));
	if (philo->data->death == 1)
	{
		pthread_mutex_unlock(&(philo->data->value));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->value));
	return (0);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->r_fork->lock));
	philo->r_fork->taked = 0;
	pthread_mutex_unlock(&(philo->r_fork->lock));
	pthread_mutex_lock(&(philo->l_fork->lock));
	philo->l_fork->taked = 0;
	pthread_mutex_unlock(&(philo->l_fork->lock));
}

int	sleep_philo(t_philo *philo)
{
	int	t_sleep;

	pthread_mutex_lock(&(philo->data->value));
	if (philo->data->death == 0)
	{
		pthread_mutex_unlock(&(philo->data->value));
		mprintf(philo, "is sleeping");
		pthread_mutex_lock(&philo->mtime);
		t_sleep = philo->t_sleep;
		pthread_mutex_unlock(&philo->mtime);
		if (my_sleep(philo, t_sleep))
			return (1);
		return (0);
	}
	pthread_mutex_unlock(&(philo->data->value));
	return (0);
}

int	eat_philo(t_philo *philo)
{
	int	eat_time;

	if (take_forks(philo))
		return (1);
	pthread_mutex_lock(&(philo->mtime));
	mprintf(philo, "is eating");
	philo->count_meal++;
	philo->last_meal = get_time() - philo->init_time;
	eat_time = philo->t_eat;
	pthread_mutex_unlock(&(philo->mtime));
	if (my_sleep(philo, eat_time))
		return (1);
	put_forks(philo);
	if (sleep_philo(philo))
		return (1);
	pthread_mutex_lock(&(philo)->data->value);
	if (philo->data->death == 1)
	{
		pthread_mutex_unlock(&(philo)->data->value);
		return (1);
	}
	pthread_mutex_unlock(&(philo)->data->value);
	return (0);
}
