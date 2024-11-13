/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:42:24 by mguy              #+#    #+#             */
/*   Updated: 2024/03/22 16:07:16 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../minilibx/mlx.h"

int	events(t_data *data);
int	key_press(int keycode, t_data *data);
int	can_move(t_data *data, int new_x, int new_y);
int	close_win(t_data *data);

int	can_move(t_data *data, int new_x, int new_y)
{
	int		map_x;
	int		map_y;
	char	tile;

	map_x = new_x / TILE_SIZE;
	map_y = new_y / TILE_SIZE;
	if (map_x < 0 || map_x >= data->map_width || map_y < 0
		|| map_y >= data->map_height)
		return (0);
	tile = data->map[map_y][map_x];
	return (tile == '0' || tile == 'P' || tile == 'E' || tile == 'C'
		|| tile == 'K' || tile == 'O');
}

int	close_win(t_data *data)
{
	if (data->map != NULL)
		free_tab(data);
	mlx_clear_window(data->mlx, data->win);
	destroy_all(data);
	exit(0);
	return (0);
}

void	check_win(t_data *data)
{
	char	c;
	int		map_x;
	int		map_y;

	map_x = data->char_offset_x / TILE_SIZE;
	map_y = data->char_offset_y / TILE_SIZE;
	c = data->map[map_y][map_x];
	if (c == 'O')
	{
		ft_printf("YOU WIN !\n");
		close_win(data);
	}
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_win(data);
	else if (keycode == KEY_W && can_move(data,
			data->char_offset_x, data->char_offset_y - SCROLL_STEP))
		data->char_offset_y -= SCROLL_STEP;
	else if (keycode == KEY_S && can_move(data,
			data->char_offset_x, data->char_offset_y + SCROLL_STEP))
		data->char_offset_y += SCROLL_STEP;
	else if (keycode == KEY_A && can_move(data,
			data->char_offset_x - SCROLL_STEP, data->char_offset_y))
		data->char_offset_x -= SCROLL_STEP;
	else if (keycode == KEY_D && can_move(data,
			data->char_offset_x + SCROLL_STEP, data->char_offset_y))
		data->char_offset_x += SCROLL_STEP;
	else
		return (0);
	data->nb_mouv++;
	ft_printf("Nb_mouv: %i\n", data->nb_mouv);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	check_win(data);
	return (0);
}

int	events(t_data *data)
{
	char	c;
	int		map_x;
	int		map_y;
	int		action;

	action = 0;
	map_x = data->char_offset_x / TILE_SIZE;
	map_y = data->char_offset_y / TILE_SIZE;
	c = data->map[map_y][map_x];
	if (c == 'C')
	{
		data->map[map_y][map_x] = 'K';
		data->check++;
		action = 1;
	}
	else if (data->check == data->total_check && data->open != 1)
		action = open_exit(data);
	if (action == 1)
	{
		mlx_clear_window(data->mlx, data->win);
		draw_map(data);
	}
	return (0);
}
