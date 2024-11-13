/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:36:51 by mguy              #+#    #+#             */
/*   Updated: 2024/09/04 18:33:35 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	right_fork(t_philo *philo)
{
	if (is_dead(philo))
		return (1);
	pthread_mutex_lock(&philo->r_fork->lock);
	while (philo->r_fork->taked == 1)
	{
		pthread_mutex_unlock(&philo->r_fork->lock);
		if (is_dead(philo))
			return (1);
		pthread_mutex_lock(&philo->r_fork->lock);
	}
	philo->r_fork->taked = 1;
	pthread_mutex_unlock(&philo->r_fork->lock);
	mprintf(philo, "has taken a fork");
	return (0);
}

int	left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->lock);
	while (philo->l_fork->taked == 1)
	{
		pthread_mutex_unlock(&philo->l_fork->lock);
		if (is_dead(philo))
			return (1);
		pthread_mutex_lock(&philo->l_fork->lock);
	}
	philo->l_fork->taked = 1;
	pthread_mutex_unlock(&philo->l_fork->lock);
	mprintf(philo, "has taken a fork");
	return (0);
}
