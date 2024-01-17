/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:00 by ycarpent          #+#    #+#             */
/*   Updated: 2023/08/20 17:50:36 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

unsigned int	check_column_top(t_data *data, unsigned int index)
{
	unsigned int	line;
	unsigned int	col;
	unsigned int	max_value;
	unsigned int	max_count;

	col = 0;
	while (col < index % SIZE)
	{
		line = 0;
		max_value = 0;
		max_count = 0;
		while (line < SIZE)
		{
			if (data->tab[line][col] > max_value)
			{
				max_value = data->tab[line][col];
				max_count += 1;
			}
			line++;
		}
		if (max_count != data->key[col])
			return (0);
		col++;
	}
	return (1);
}

unsigned int	check_column_bottom(t_data *data, unsigned int index)
{
	unsigned int	line;
	unsigned int	col;
	unsigned int	max_value;
	unsigned int	max_count;

	col = 0;
	while (col < index % SIZE)
	{
		line = 0;
		max_value = 0;
		max_count = 0;
		while (line < SIZE)
		{
			if (data->tab[SIZE - 1 - line][col] > max_value)
			{
				max_value = data->tab[SIZE - 1 - line][col];
				max_count = max_count + 1;
			}
			line++;
		}
		if (max_count != data->key[SIZE + col])
			return (0);
		col++;
	}
	return (1);
}

unsigned int	check_line_left(t_data *data, unsigned int index)
{
	unsigned int	line;
	unsigned int	col;
	unsigned int	max_value;
	unsigned int	max_count;

	line = 0;
	while (line < index / SIZE)
	{
		col = 0;
		max_value = 0;
		max_count = 0;
		while (col < SIZE)
		{
			if (data->tab[line][col] > max_value)
			{
				max_value = data->tab[line][col];
				max_count = max_count + 1;
			}
			col++;
		}
		if (max_count != data->key[2 * SIZE + line])
			return (0);
		line++;
	}
	return (1);
}

unsigned int	check_line_right(t_data *data, unsigned int index)
{
	unsigned int	line;
	unsigned int	col;
	unsigned int	max_value;
	unsigned int	max_count;

	line = 0;
	while (line < index / SIZE)
	{
		col = 0;
		max_value = 0;
		max_count = 0;
		while (col < SIZE)
		{
			if (data->tab[line][SIZE - 1 - col] > max_value)
			{
				max_value = data->tab[line][SIZE - 1 - col];
				max_count = max_count + 1;
			}
			col++;
		}
		if (max_count != data->key[3 * SIZE + line])
			return (0);
		line++;
	}
	return (1);
}

unsigned int	final_check(t_data *data)
{
	unsigned int	index;

	index = SIZE * SIZE;
	if (check_column_top(data, index) == 1
		&& check_column_bottom(data, index) == 1
		&& check_line_left(data, index) == 1
		&& check_line_right(data, index) == 1)
		return (1);
	else
		return (0);
}
