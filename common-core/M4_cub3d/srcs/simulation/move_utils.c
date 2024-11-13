/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:48:48 by mguy              #+#    #+#             */
/*   Updated: 2024/09/26 17:16:07 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	move_player(t_cub3d *c, float x_offset, float y_offset, int *move)
{
	float	new_x;
	float	new_y;
	float	dist;

	*move = 1;
	dist = 0.2;
	new_x = c->simulation->player->x + x_offset;
	new_y = c->simulation->player->y + y_offset;
	if (c->parsing->map[(int)new_y][(int)new_x] != '1'
		&& c->parsing->map[(int)new_y][(int)new_x] != '\0'
		&& c->parsing->map[(int)(new_y + dist)][(int)(new_x + dist)] != '1'
		&& c->parsing->map[(int)(new_y + dist)][(int)(new_x + dist)] != '\0'
		&& c->parsing->map[(int)(new_y + dist)][(int)(new_x - dist)] != '1'
		&& c->parsing->map[(int)(new_y + dist)][(int)(new_x - dist)] != '\0'
		&& c->parsing->map[(int)(new_y - dist)][(int)(new_x + dist)] != '1'
		&& c->parsing->map[(int)(new_y - dist)][(int)(new_x + dist)] != '\0'
		&& c->parsing->map[(int)(new_y - dist)][(int)(new_x - dist)] != '1'
		&& c->parsing->map[(int)(new_y - dist)][(int)(new_x - dist)] != '\0')
	{
		c->simulation->player->x = new_x;
		c->simulation->player->y = new_y;
	}
}

void	move_forward_backward(t_cub3d *c, int *moved)
{
	if (c->simulation->keys->w)
		move_player(c, MOVE_SPEED * cos(c->simulation->player->angle),
			MOVE_SPEED * sin(c->simulation->player->angle), moved);
	if (c->simulation->keys->s)
		move_player(c, -MOVE_SPEED * cos(c->simulation->player->angle),
			-MOVE_SPEED * sin(c->simulation->player->angle), moved);
}

void	move_left_right(t_cub3d *c, int *moved)
{
	if (c->simulation->keys->a)
		move_player(c, MOVE_SPEED * sin(c->simulation->player->angle),
			-MOVE_SPEED * cos(c->simulation->player->angle), moved);
	if (c->simulation->keys->d)
		move_player(c, -MOVE_SPEED * sin(c->simulation->player->angle),
			MOVE_SPEED * cos(c->simulation->player->angle), moved);
}

void	rotate_player(t_cub3d *cube3d, int *moved)
{
	if (cube3d->simulation->keys->left)
	{
		cube3d->simulation->player->angle -= (PI / ROTATE_SPEED);
		*moved = 1;
	}
	if (cube3d->simulation->keys->right)
	{
		cube3d->simulation->player->angle += (PI / ROTATE_SPEED);
		*moved = 1;
	}
}
