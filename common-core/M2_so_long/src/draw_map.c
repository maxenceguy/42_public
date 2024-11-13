/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:50:34 by mguy              #+#    #+#             */
/*   Updated: 2024/03/22 16:07:40 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../minilibx/mlx.h"

int		open_exit(t_data *d);
int		put_sprite(t_data *d, char tile, int tx, int ty);
int		find_sprite(t_data *data, int char_x, int char_y);
void	draw_map(t_data *data);

int	open_exit(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x])
		{
			if (d->map[y][x] == 'E')
				d->map[y][x] = 'O';
			x++;
		}
		y++;
	}
	d->open = 1;
	return (1);
}

int	put_sprite(t_data *d, char tile, int tx, int ty)
{
	if (tile == '0' || tile == 'P')
		mlx_put_image_to_window(d->mlx, d->win, d->floor, tx, ty);
	else if (tile == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->wall, tx, ty);
	else if (tile == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->door_close, tx, ty);
	else if (tile == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->chest_close, tx, ty);
	else if (tile == 'K')
		mlx_put_image_to_window(d->mlx, d->win, d->chest_open, tx, ty);
	else if (tile == 'O')
		mlx_put_image_to_window(d->mlx, d->win, d->door_open, tx, ty);
	return (0);
}

int	find_sprite(t_data *data, int char_x, int char_y)
{
	int		y;
	int		x;
	char	tile;
	int		tile_x;
	int		tile_y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			tile = data->map[y][x];
			tile_x = (x * TILE_SIZE) + char_x;
			tile_y = (y * TILE_SIZE) + char_y;
			put_sprite(data, tile, tile_x, tile_y);
			x++;
		}
		y++;
	}
	return (0);
}

void	draw_map(t_data *data)
{
	int	char_x;
	int	char_y;
	int	char_tile_x;
	int	char_tile_y;

	char_x = (WIN_WIDTH / 2 - TILE_SIZE / 2) - data->char_offset_x;
	char_y = (WIN_HEIGHT / 2 - TILE_SIZE / 2) - data->char_offset_y;
	find_sprite(data, char_x, char_y);
	char_tile_x = (WIN_WIDTH / 2 - TILE_SIZE / 2) - TILE_SIZE / 2;
	char_tile_y = (WIN_HEIGHT / 2 - TILE_SIZE / 2) - TILE_SIZE / 2;
	mlx_put_image_to_window(data->mlx, data->win, data->character,
		char_tile_x, char_tile_y);
}
