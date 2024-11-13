/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:56:18 by mguy              #+#    #+#             */
/*   Updated: 2024/09/23 02:29:12 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	init_player_pos(t_simulation *sim, t_parsing *parsing, int x, int y)
{
	sim->player->x = (float)x + 0.5;
	sim->player->y = (float)y + 0.5;
	if (parsing->map[y][x] == 'N')
		sim->player->angle = 3 * M_PI / 2;
	else if (parsing->map[y][x] == 'S')
		sim->player->angle = M_PI / 2;
	else if (parsing->map[y][x] == 'W')
		sim->player->angle = M_PI;
	else if (parsing->map[y][x] == 'E')
		sim->player->angle = 0;
	parsing->map[y][x] = '0';
}

void	draw_map(t_simulation *sim, t_parsing *parsing)
{
	int	x;
	int	y;

	y = -1;
	while (parsing->map[++y])
	{
		x = -1;
		while (parsing->map[y][++x])
		{
			if (parsing->map[y][x] == 'N' || parsing->map[y][x] == 'S'
				|| parsing->map[y][x] == 'W' || parsing->map[y][x] == 'E')
			{
				init_player_pos(sim, parsing, x, y);
			}
		}
	}
}

void	draw_little_map(t_parsing *parsing, t_simulation *sim, int tile_size)
{
	int	x;
	int	y;

	y = 0;
	while (parsing->map[y])
	{
		x = 0;
		while (parsing->map[y][x])
		{
			if (parsing->map[y][x] == '1')
				draw_tile(sim, x, y, 0xFFFFFF);
			else if (parsing->map[y][x] == '0')
				draw_tile(sim, x, y, 0x000000);
			x++;
		}
		y++;
	}
	draw_player(sim, sim->player->x, sim->player->y, tile_size);
	draw_direction_vector(sim, sim->player);
}

void	draw_map_hook(t_simulation *sim, t_parsing *parsing, int tile_size)
{
	render_3d_projection(parsing, sim, sim->player);
	draw_little_map(parsing, sim, tile_size);
}
