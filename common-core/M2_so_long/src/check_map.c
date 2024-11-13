/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:48:42 by mguy              #+#    #+#             */
/*   Updated: 2024/03/28 10:25:21 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	rect_map(t_data *data, char **m);
int		comp_components(t_data *data, char c, int *l);
int		components(t_data *data, char **map);
void	check_map(t_data *data);

void	rect_map(t_data *data, char **m)
{
	int	y;
	int	x1;
	int	x;

	x1 = ft_strlen(m[0]);
	y = 0;
	while (m[y])
	{
		x = 0;
		while (m[y][x])
		{
			if ((x == 0 || y == 0 || !m[y][x + 1] || !m[y + 1])
				&& m[y][x] != '1')
				exit_error(data, "Map not closed.\n");
			x++;
		}
		if (x != x1)
			exit_error(data, "All lines are not the same size.\n");
		y++;
	}
	if (y == x1)
		exit_error(data, "It's not a rectangle.\n");
}

int	comp_components(t_data *data, char c, int *l)
{
	if (c == '0')
		l[0]++;
	if (c == '1')
		l[1]++;
	if (c == 'P' && l[2] < 2)
		l[2]++;
	if (c == 'P' && l[2] >= 2)
		return (free(l), exit_error(data, "Too P components.\n"), 0);
	if (c == 'C')
		l[3]++;
	if (c == 'E' && l[4] < 2)
		l[4]++;
	if (c == 'E' && l[4] >= 2)
		return (free(l), exit_error(data, "Too E components.\n"), 0);
	if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
		return (free(l), exit_error(data, "Bad components.\n"), 0);
	return (0);
}

// int l = [0, 1, P, C E];

int	components(t_data *data, char **map)
{
	int	*l;
	int	y;
	int	x;

	l = ft_calloc(5, sizeof(int));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			comp_components(data, map[y][x], l);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < 5)
	{
		if (l[x] == 0)
			return (free(l), exit_error(data, "Missing components.\n"), 0);
		x++;
	}
	free(l);
	return (0);
}

void	check_map(t_data *data)
{
	rect_map(data, data->map);
	components(data, data->map);
	if (resolved_map(data) == -1)
		exit_error(data, "Malloc error.\n");
}
