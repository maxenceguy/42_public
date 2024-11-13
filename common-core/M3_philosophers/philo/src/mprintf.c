/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:29:54 by mguy              #+#    #+#             */
/*   Updated: 2024/09/04 18:32:35 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	mprintf(t_philo *philo, char *s)
{
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&(philo->data->printf_mutex));
	printf("%lld %d %s\n", get_time() - philo->data->init_time, philo->id + 1,
		s);
	pthread_mutex_unlock(&(philo->data->printf_mutex));
}
