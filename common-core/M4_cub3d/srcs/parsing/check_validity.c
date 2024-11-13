/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:41:00 by mguy              #+#    #+#             */
/*   Updated: 2024/09/25 09:44:34 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	valid_files(t_parsing *p)
{
	int	fd;

	fd = open(p->no, O_RDONLY, 0);
	if (fd < 0)
		return (printf("NO error, the file cannot be read\n"), 1);
	close(fd);
	fd = open(p->so, O_RDONLY, 0);
	if (fd < 0)
		return (printf("SO error, the file cannot be read\n"), 1);
	close(fd);
	fd = open(p->we, O_RDONLY, 0);
	if (fd < 0)
		return (printf("WE error, the file cannot be read\n"), 1);
	close(fd);
	fd = open(p->ea, O_RDONLY, 0);
	if (fd < 0)
		return (printf("EA error, the file cannot be read\n"), 1);
	close(fd);
	return (0);
}

int	check_characters(t_parsing *p)
{
	int		y;
	int		x;
	char	c;
	int		count;

	y = 0;
	count = 0;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x])
		{
			c = p->map[y][x];
			if (c != ' ' && c != '1' && c != '0' && c != 'N' && c != 'S'
				&& c != 'E' && c != 'W')
				return (printf("Map error: bad characters finded\n"), 1);
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (printf("Map error: More than 1 character N, S, W or E\n"), 1);
	return (0);
}

int	is_open(t_parsing *p, int y, int x)
{
	if (x == 0 || y == 0 || p->map[y + 1] == NULL || p->map[y][x + 1] == '\0')
		return (1);
	if (p->map[y + 1][x] == ' ' || p->map[y - 1][x] == ' ')
		return (1);
	if (p->map[y][x + 1] == ' ' || p->map[y][x - 1] == ' ')
		return (1);
	return (0);
}

int	check_closed_map(t_parsing *p)
{
	int	y;
	int	x;

	y = 0;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x])
		{
			if (p->map[y][x] == '0' || p->map[y][x] == 'N'
					|| p->map[y][x] == 'S' || p->map[y][x] == 'E'
					|| p->map[y][x] == 'W')
			{
				if (is_open(p, y, x))
					return (printf("Map error: opened at %i - %i\n", y, x), 1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_validity(t_parsing *p)
{
	if (valid_files(p))
		return (1);
	if (check_characters(p))
		return (1);
	if (check_closed_map(p))
		return (1);
	return (0);
}
