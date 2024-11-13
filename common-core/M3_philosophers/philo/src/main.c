/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:38:23 by mguy              #+#    #+#             */
/*   Updated: 2024/08/29 17:25:22 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy(t_philo *philo, t_fork *fork)
{
	int	i;

	i = 0;
	while (philo->data->nb_philo > ++i)
		destroy_mutex(&(philo[i]), 4);
	pthread_mutex_destroy(&(philo->data->printf_mutex));
	pthread_mutex_destroy(&(philo->data->value));
	free(fork);
	free(philo->data);
	free(philo);
}

int	main(int ac, char *av[])
{
	t_philo	*philo;
	t_fork	*fork;
	t_data	*data;

	if (ac >= 5 && ac <= 6)
	{
		if (check_params(ac, av))
			return (1);
		data = malloc(sizeof(t_data));
		if (data == NULL)
			return (0);
		if (init(ac, av, data))
			return (1);
		if (init_philo(&philo, &fork, data))
			return (free(data), 1);
		if (life(philo, data))
			return (destroy(philo, fork), 1);
		destroy(philo, fork);
	}
	else
	{
		printf("Arguments :number_of_philosophers time_to_die time_to_eat");
		printf(" time_to_sleep [number_of_times_each_philosopher_must_eat]");
	}
	return (0);
}
