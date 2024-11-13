/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:52 by mguy              #+#    #+#             */
/*   Updated: 2024/08/29 17:26:14 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&(philo->mtime), NULL))
		return (1);
	if (pthread_mutex_init(&(philo->r_fork->lock), NULL))
		return (destroy_mutex(philo, 1), 1);
	if (pthread_mutex_init(&(philo->mstart), NULL))
		return (destroy_mutex(philo, 2), 1);
	if (philo->data->nb_philo > 1)
	{
		if (pthread_mutex_init(&(philo->l_fork->lock), NULL))
			return (destroy_mutex(philo, 3), 1);
	}
	return (0);
}

void	destroy_mutex(t_philo *philo, int i)
{
	if (i >= 1)
		pthread_mutex_destroy(&(philo->mtime));
	if (i >= 2 && philo->id > philo->nb_philo)
		pthread_mutex_destroy(&(philo->r_fork->lock));
	if (i >= 3)
		pthread_mutex_destroy(&(philo->mstart));
	if (i >= 4 && philo->data->nb_philo > 1)
		pthread_mutex_destroy(&(philo->l_fork->lock));
}

int	error_init(t_philo **philo, t_data *data, int i)
{
	if (pthread_mutex_init(&(data->value), NULL))
	{
		while (--i >= 0)
			destroy_mutex(&(*philo[i]), 4);
		return (free(philo), free(fork), 1);
	}
	if (pthread_mutex_init(&(data->printf_mutex), NULL))
	{
		pthread_mutex_destroy(&data->value);
		while (--i >= 0)
			destroy_mutex(&(*philo[i]), 4);
		return (free(philo), free(fork), 1);
	}
	return (0);
}
