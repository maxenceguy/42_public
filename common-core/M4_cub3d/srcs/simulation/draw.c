/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:25:47 by mguy              #+#    #+#             */
/*   Updated: 2024/09/25 10:45:06 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	draw_tile(t_simulation *sim, int x, int y, int color)
{
	int	i;
	int	j;
	int	screen_x;
	int	screen_y;

	screen_x = x * sim->tile_size;
	screen_y = y * sim->tile_size;
	i = 0;
	while (i < sim->tile_size)
	{
		j = 0;
		while (j < sim->tile_size)
		{
			my_pixel_put((int)(screen_x + i), (int)(screen_y + j),
				sim->img, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_simulation *sim, float x, float y, float tile_size)
{
	float	screen_x;
	float	screen_y;
	float	player_radius;
	float	i;
	float	j;

	screen_x = (x * tile_size);
	screen_y = (y * tile_size);
	player_radius = 3;
	i = -player_radius;
	while (i < player_radius)
	{
		j = -player_radius;
		while (j < player_radius)
		{
			if (i * i + j * j <= player_radius * player_radius)
				my_pixel_put(screen_x + i, screen_y + j, sim->img, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_texture_line(t_simulation *sim, int x, t_texture *texture,
		t_draw_texture_line	*dt)
{
	dt->step = (float)texture->height / dt->wall_height;
	dt->tex_pos = 0.0f;
	if (dt->wall_height > WINDOW_HEIGHT)
	{
		dt->tex_pos = (dt->wall_height - WINDOW_HEIGHT) / 2 * dt->step;
		dt->wall_height = WINDOW_HEIGHT;
	}
	dt->tex_x = (int)(dt->textur_x_offset * texture->width);
	dt->y = dt->wall_start;
	while (dt->y <= dt->wall_end)
	{
		dt->tex_y = (int)dt->tex_pos & (texture->height - 1);
		dt->tex_pos += dt->step;
		dt->color = get_texture_pixel_color(texture, dt->tex_x, dt->tex_y);
		my_pixel_put(x, dt->y, sim->img, dt->color);
		dt->y++;
	}
}
