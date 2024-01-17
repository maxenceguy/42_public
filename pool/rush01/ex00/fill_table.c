/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:57:29 by alermolo          #+#    #+#             */
/*   Updated: 2023/08/20 18:03:53 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

unsigned int	is_safe(t_data *data, unsigned int index, unsigned int value)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < index / SIZE)
	{
		if (data->tab[i][index % SIZE] == value)
			return (0);
		i++;
	}
	while (j < index % SIZE)
	{
		if (data->tab[index / SIZE][j] == value)
			return (0);
		j++;
	}
	if (index % SIZE == 0)
		if (!check_line_left(data, index) || !check_line_right(data, index))
			return (0);
	if (index / SIZE == SIZE - 1)
		if (!check_column_top(data, index) || !check_column_bottom(data, index))
			return (0);
	return (1);
}

unsigned int	fill_table(t_data *data, unsigned int index)
{
	unsigned int	value;

	if (index == SIZE * SIZE && final_check(data))
		return (1);
	value = 1;
	while (value <= SIZE)
	{
		if (is_safe(data, index, value))
		{
			data->tab[index / SIZE][index % SIZE] = value;
			if (fill_table(data, index + 1))
				return (1);
		}
		value++;
	}
	return (0);
}
