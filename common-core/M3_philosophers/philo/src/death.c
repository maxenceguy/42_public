/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:51:05 by mguy              #+#    #+#             */
/*   Updated: 2024/09/04 18:33:25 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_philo_death(t_philo *philo)
{
	long long	time_since_last_meal;
	long long	data_init_time;

	time_since_last_meal = 0;
	data_init_time = 0;
	pthread_mutex_lock(&philo->data->value);
	data_init_time = philo->data->init_time;
	pthread_mutex_unlock(&philo->data->value);
	pthread_mutex_lock(&(philo->mtime));
	time_since_last_meal = get_time() - data_init_time - philo->last_meal;
	if (time_since_last_meal >= philo->t_die)
	{
		pthread_mutex_unlock(&(philo->mtime));
		end(philo);
		return (1);
	}
	pthread_mutex_unlock(&(philo->mtime));
	return (0);
}

int	end_meal(t_philo *philo)
{
	int	i;
	int	check;
	int	nb_philo;

	i = 0;
	check = 0;
	pthread_mutex_lock(&(philo[i].data->value));
	nb_philo = philo[i].data->nb_philo;
	pthread_mutex_unlock(&(philo[i].data->value));
	while (i < nb_philo)
	{
		pthread_mutex_lock(&(philo[i].mtime));
		if (philo[i].count_meal >= philo[i].round && philo[i].round != -1)
			check++;
		pthread_mutex_unlock(&(philo[i].mtime));
		i++;
	}
	if (check >= nb_philo)
	{
		pthread_mutex_lock(&(philo->data->value));
		philo->data->death = 1;
		pthread_mutex_unlock(&(philo->data->value));
		return (1);
	}
	return (0);
}

void	check_death(t_philo *philo, int nb_philo)
{
	int	i;
	int	alive;

	alive = 1;
	while (alive)
	{
		i = 0;
		while (i < nb_philo && alive)
		{
			if (end_meal(philo) || check_philo_death(&philo[i]))
			{
				alive = 0;
				return ;
			}
			i++;
		}
	}
}
