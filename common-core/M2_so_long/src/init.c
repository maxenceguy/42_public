/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:47:53 by mguy              #+#    #+#             */
/*   Updated: 2024/03/22 16:09:10 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../minilibx/mlx.h"

void	get_env(t_data *data);
void	set_initial_offsets(t_data *data);

void	get_env(t_data *d)
{
	int	w;
	int	h;

	d->floor = mlx_xpm_file_to_image(d->mlx, "img/floor.xpm", &w, &h);
	d->wall = mlx_xpm_file_to_image(d->mlx, "img/wall.xpm", &w, &h);
	d->character = mlx_xpm_file_to_image(d->mlx,
			"img/character40.xpm", &w, &h);
	d->door_open = mlx_xpm_file_to_image(d->mlx, "img/1door-open.xpm", &w, &h);
	d->door_close = mlx_xpm_file_to_image(d->mlx,
			"img/1door-close.xpm", &w, &h);
	d->chest_open = mlx_xpm_file_to_image(d->mlx,
			"img/1chest-open.xpm", &w, &h);
	d->chest_close = mlx_xpm_file_to_image(d->mlx,
			"img/1chest-close.xpm", &w, &h);
}

void	set_initial_offsets(t_data *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	data->open = 0;
	data->nb_mouv = 0;
	while (y < data->map_height)
	{
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'P')
			{
				data->char_offset_x = ((x) * TILE_SIZE + TILE_SIZE / 2 + 4);
				data->char_offset_y = ((y) * TILE_SIZE + TILE_SIZE / 2 + 4);
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
