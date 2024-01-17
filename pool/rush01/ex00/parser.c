/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:09:04 by mguy              #+#    #+#             */
/*   Updated: 2023/08/20 16:58:17 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

unsigned int	count_elts(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > SIZE + '0'))
			return (0);
		else if (i % 2 != 0 && str[i] != ' ')
			return (0);
		i++;
	}
	return (i);
}

unsigned int	create_key(t_data *data, char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	data->key = malloc(sizeof(unsigned int) * (SIZE * 4));
	if (data->key == NULL)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			data->key[j] = (int)str[i] - 48;
			j++;
		}
		i++;
	}
	return (0);
}

unsigned int	create_tab(t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	data->tab = malloc(sizeof(unsigned int *) * SIZE);
	if (data->tab == NULL)
		return (1);
	while (i < SIZE)
	{
		data->tab[i] = malloc(sizeof(unsigned int) * SIZE);
		if (data->tab[i] == NULL)
			return (1);
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
			data->tab[i][j++] = 0;
		i++;
	}
	return (0);
}

unsigned int	parser(t_data *data, char **argv)
{
	if (count_elts(argv[1]) != (SIZE * 2 * 4 - 1))
		return (1);
	if (create_key(data, argv[1]) == 1)
		return (1);
	if (create_tab(data) == 1)
		return (1);
	return (0);
}
