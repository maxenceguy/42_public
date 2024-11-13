/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:49:36 by mguy              #+#    #+#             */
/*   Updated: 2024/09/25 10:50:28 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	redraw(t_cub3d *cube3d)
{
	draw_map_hook(cube3d->simulation, cube3d->parsing,
		cube3d->simulation->tile_size);
	mlx_put_image_to_window(cube3d->simulation->mlx_ptr,
		cube3d->simulation->win_ptr, cube3d->simulation->img->img_ptr, 0, 0);
}

int	handle_player_movement(t_cub3d *cube3d)
{
	int	moved;

	moved = 0;
	move_forward_backward(cube3d, &moved);
	move_left_right(cube3d, &moved);
	rotate_player(cube3d, &moved);
	if (moved)
		redraw(cube3d);
	return (0);
}

int	key_press(int keycode, t_cub3d *cube3d)
{
	if (keycode == KEY_ESC)
		close_window(cube3d);
	if (keycode == KEY_W)
		cube3d->simulation->keys->w = 1;
	if (keycode == KEY_S)
		cube3d->simulation->keys->s = 1;
	if (keycode == KEY_A)
		cube3d->simulation->keys->a = 1;
	if (keycode == KEY_D)
		cube3d->simulation->keys->d = 1;
	if (keycode == KEY_LEFT)
		cube3d->simulation->keys->left = 1;
	if (keycode == KEY_RIGHT)
		cube3d->simulation->keys->right = 1;
	return (0);
}

int	key_release(int keycode, t_cub3d *cube3d)
{
	if (keycode == KEY_W)
		cube3d->simulation->keys->w = 0;
	if (keycode == KEY_S)
		cube3d->simulation->keys->s = 0;
	if (keycode == KEY_A)
		cube3d->simulation->keys->a = 0;
	if (keycode == KEY_D)
		cube3d->simulation->keys->d = 0;
	if (keycode == KEY_LEFT)
		cube3d->simulation->keys->left = 0;
	if (keycode == KEY_RIGHT)
		cube3d->simulation->keys->right = 0;
	return (0);
}
