/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:56:22 by mguy              #+#    #+#             */
/*   Updated: 2024/09/04 18:33:15 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_dead(t_philo *philo)
{
	int	death;

	pthread_mutex_lock(&(philo->data->value));
	death = philo->data->death;
	pthread_mutex_unlock(&(philo->data->value));
	return (death);
}
