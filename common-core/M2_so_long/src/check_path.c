/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:42:53 by mguy              #+#    #+#             */
/*   Updated: 2024/03/20 14:31:18 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_p(t_data *d, size_t *x, size_t *y)
{
	while (d->map[*y])
	{
		*x = 0;
		while (d->map[*y][*x])
		{
			if (d->map[*y][*x] == 'P')
				return (1);
			*x++;
		}
		*y++;
	}
	return (0);
}

int	path(t_data *d, bool v, size_t *x, size_t *y)
{
	if (d->map[*y][*x] == 'E')
		return (1);
	if (d->map[*y + 1][*x] == 0 && v[*y + 1][*x] == false)
		*y++;
	else if (d->map[*y - 1][*x] == 0 && v[*y - 1][*x] == false)
		*y--;
	else if (d->map[*y][*x + 1] == 0 && v[*y][*x + 1] == false)
		*x++;
	else if (d->map[*y][*x - 1] == 0 && v[*y][*x - 1] == false)
		*x--;
	else if (d->map[*y + 1][*x] == 'E' || d->map[*y - 1][*x] == 'E'
			|| d->map[*y][*x + 1] == 'E' || d->map[*y][*x - 1] == 'E')
		return (1);
	else if (v[*y + 1][*x] == false && v[*y - 1][*x] == false
			&& v[*y][*x + 1] == false && v[*y][*x - 1] == false)
		return (-1);
	retutn (path(d, v, x, y));
}

int	resolved_map(t_data *d)
{
	size_t	x;
	size_t	y;
	bool	v;

	v[d->map_height][d->map_width];
	x = 0;
	y = 0;
	if (!find_p(d, &x, &y))
		exit_error(d, "No P finded.\n");
	if (path(d, v, &x, &y) == (-1))
		exit_error(d, "No path finded.\n");
	return (1);
}
