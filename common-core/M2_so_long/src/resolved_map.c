/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolved_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:45:20 by mguy              #+#    #+#             */
/*   Updated: 2024/03/28 10:29:00 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdbool.h>

int	find_p(t_data *d, int *x, int *y);
int	path(t_data *d, int **v, int x, int y);
int	resolved_map(t_data *d);

int	**create_array2(int size, int y, int x)
{
	int	**arr;
	int	y1;
	int	x1;

	y1 = 0;
	arr = malloc(sizeof(int *) * (y + 1));
	if (arr == NULL)
		return (NULL);
	while (y1 < y)
	{
		x1 = 0;
		arr[y1] = malloc(size * x);
		if (arr[y1] == NULL)
			return (free(arr), NULL);
		while (x1 < x)
		{
			arr[y1][x1] = 0;
			x1++;
		}
		y1++;
	}
	arr[y1] = NULL;
	return (arr);
}

void	free_arr(int **arr, t_data *d)
{
	int	y;

	y = 0;
	while (y < d->map_height + 1)
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}

int	find_p(t_data *d, int *x, int *y)
{
	*y = 0;
	while (d->map[*y])
	{
		*x = 0;
		while (d->map[*y][*x])
		{
			if (d->map[*y][*x] == 'P')
				return (1);
			*x += 1;
		}
		*y += 1;
	}
	return (0);
}

int	path(t_data *d, int **v, int x, int y)
{
	if (y < 0 || x < 0 || y > d->map_height || x > d->map_width)
		return (-1);
	else if (d->map[y][x] == '1' || v[y][x] == 1)
		return (-1);
	v[y][x] = 1;
	if (d->map[y][x] == 'E')
		return (1);
	else if (path(d, v, x, y - 1) == 1)
		return (1);
	else if (path(d, v, x + 1, y) == 1)
		return (1);
	else if (path(d, v, x, y + 1) == 1)
		return (1);
	else if (path(d, v, x - 1, y) == 1)
		return (1);
	return (-1);
}

int	resolved_map(t_data *d)
{
	int	x;
	int	y;
	int	**v;

	x = 0;
	y = 0;
	v = create_array2(sizeof(int), d->map_height, d->map_width);
	if (v == NULL)
		return (-1);
	while (y < d->map_height)
	{
		x = 0;
		while (x < d->map_width)
		{
			v[y][x] = 0;
			x++;
		}
		y++;
	}
	x = 0;
	y = 0;
	if (!find_p(d, &x, &y) || path(d, v, x, y) == (-1))
		return (free_arr(v, d), exit_error(d, "No path finded.\n"), 1);
	return (free_arr(v, d), 1);
}
