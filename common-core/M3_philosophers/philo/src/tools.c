/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:14:15 by mxc               #+#    #+#             */
/*   Updated: 2024/06/12 14:28:21 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_int_max(char *s)
{
	if (s[0] == '-')
		return (0);
	if (ft_strlen(s) >= 10 && (s[0] > '2' || s[1] > '1' || s[2] > '4'
			|| s[3] > '7' || s[4] > '4' || s[5] > '8' || s[6] > '3'
			|| s[7] > '6' || s[8] > '4' || s[9] > '7'))
		return (1);
	return (0);
}

int	ft_int_min(char *s)
{
	if (ft_strlen(s) >= 11 && (s[1] > '2' || s[2] > '1' || s[3] > '4'
			|| s[4] > '7' || s[5] > '4' || s[6] > '8' || s[7] > '3'
			|| s[8] > '6' || s[9] > '4' || s[10] > '8'))
		return (1);
	return (0);
}

int	ft_is_number(int ac, char **av)
{
	int	i;
	int	y;

	i = 1;
	while (i < ac)
	{
		y = 0;
		while (av[i][y])
		{
			if (av[i][y] < 48 || av[i][y] > 57)
				return (printf("Enter only numbers.\n"), 1);
			y++;
		}
		if (ft_int_max(av[i]) || ft_int_min(av[i]))
			return (printf("Number(s) too high or too low.\n"), 1);
		i++;
	}
	return (0);
}

int	check_params(int ac, char **av)
{
	int	i;

	i = 1;
	if (ft_is_number(ac, av))
		return (1);
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 1)
			return (1);
		i++;
	}
	return (0);
}
