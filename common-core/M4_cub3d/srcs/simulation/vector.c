/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:37:15 by mguy              #+#    #+#             */
/*   Updated: 2024/09/25 12:29:01 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	pimped_cast_vector(float num)
{
	int	rounded_num;

	rounded_num = (int)(num + 0.5);
	return (rounded_num);
}

void	draw_line(t_simulation *sim, t_draw_line *dl, int color)
{
	dl->dx = (int)dl->end_x - (int)dl->s_x;
	dl->dy = (int)dl->end_y - (int)dl->s_y;
	if (abs(dl->dx) > abs(dl->dy))
		dl->step = abs(dl->dx);
	else
		dl->step = abs(dl->dy);
	dl->x_inc = dl->dx / (float)dl->step;
	dl->y_inc = dl->dy / (float)dl->step;
	dl->x = (int)dl->s_x;
	dl->y = (int)dl->s_y;
	dl->i = 0;
	while (dl->i <= dl->step)
	{
		my_pixel_put((int)dl->x, (int)dl->y, sim->img, color);
		dl->x += dl->x_inc;
		dl->y += dl->y_inc;
		dl->i++;
	}
}

void	draw_direction_vector(t_simulation *sim, t_player *player)
{
	t_draw_line	dl;

	dl.s_x = player->x * (float)sim->tile_size;
	dl.s_y = player->y * (float)sim->tile_size;
	dl.end_x = dl.s_x + cos(player->angle) * 7.0;
	dl.end_y = dl.s_y + sin(player->angle) * 7.0;
	draw_line(sim, &dl, 0x0000FF);
}
