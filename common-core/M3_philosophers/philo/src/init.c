/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:59:43 by mguy              #+#    #+#             */
/*   Updated: 2024/08/29 17:26:24 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	copy_data(t_philo *philo, t_data *data)
{
	philo->nb_philo = data->nb_philo;
	philo->t_die = data->t_die;
	philo->t_eat = data->t_eat;
	philo->t_sleep = data->t_sleep;
	philo->round = data->round;
	philo->init_time = data->init_time;
}

int	create_philo(t_data *data, t_philo *philo, t_fork **fork, int i)
{
	philo->id = i;
	philo->last_meal = 0;
	philo->count_meal = 0;
	philo->eating = 0;
	philo->r_hand = 1;
	philo->l_hand = 0;
	philo->data = data;
	copy_data(philo, data);
	philo->r_fork = &((*fork)[i]);
	philo->r_fork->taked = 0;
	if (philo->data->nb_philo > 1 && i == data->nb_philo - 1)
		philo->l_fork = &((*fork)[0]);
	else if (philo->data->nb_philo > 1)
		philo->l_fork = &((*fork)[i + 1]);
	if (philo->nb_philo > 1)
		philo->l_fork->taked = 0;
	if (init_mutex(philo))
		return (1);
	return (0);
}

int	init_philo(t_philo **philo, t_fork **fork, t_data *data)
{
	int	i;

	(*philo) = malloc(sizeof(t_philo) * data->nb_philo);
	if ((*philo) == NULL)
		return (printf("Error malloc philo.\n"), 1);
	(*fork) = malloc(sizeof(t_fork) * data->nb_philo);
	if ((*fork) == NULL)
		return (free(*philo), printf("Error malloc fork.\n"), 1);
	i = 0;
	while (i < data->nb_philo)
	{
		if (create_philo(data, &((*philo)[i]), fork, i))
		{
			while (--i >= 0)
				destroy_mutex(&(*philo[i]), 4);
			return (free(philo), free(fork), 1);
		}
		i++;
	}
	if (error_init(philo, data, i))
		return (1);
	return (0);
}

int	init(int ac, char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->death = 0;
	data->ready = 0;
	data->init_time = 0;
	data->start = false;
	data->printf = false;
	if (ac == 6)
		data->round = ft_atoi(av[5]);
	else
		data->round = -1;
	return (0);
}
