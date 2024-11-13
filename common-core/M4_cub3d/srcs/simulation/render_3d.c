/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:46:03 by mguy              #+#    #+#             */
/*   Updated: 2024/09/25 12:21:33 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	calculate_wall_dimensions(t_render3d *r)
{
	if (r->corrected_distance < 0.2)
		r->corrected_distance = 0.2;
	r->wall_height = ((float)WINDOW_HEIGHT / r->corrected_distance);
	r->wall_start = (WINDOW_HEIGHT / 2) - (r->wall_height / 2);
	r->wall_end = (WINDOW_HEIGHT / 2) + (r->wall_height / 2);
	if (r->wall_start < 0)
		r->wall_start = 0;
	if (r->wall_end >= WINDOW_HEIGHT)
		r->wall_end = WINDOW_HEIGHT - 1;
}

static void	render_ceiling_and_floor(int x, t_simulation *sim, t_parsing *pars)
{
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
		my_pixel_put_rgb(x, y++, sim->img, pars->c);
	while (y < WINDOW_HEIGHT)
		my_pixel_put_rgb(x, y++, sim->img, pars->f);
}

static void	render_wall(t_render3d *r, t_simulation *sim, int x)
{
	t_texture			*texture;
	t_draw_texture_line	dtl;

	if (r->side == 0)
		r->textur_x_offset = r->hit_y - floor(r->hit_y);
	else
		r->textur_x_offset = r->hit_x - floor(r->hit_x);
	texture = select_texture(sim, r->side);
	dtl.wall_start = r->wall_start;
	dtl.wall_end = r->wall_end;
	dtl.wall_height = r->wall_height;
	dtl.textur_x_offset = r->textur_x_offset;
	draw_texture_line(sim, x, texture, &dtl);
}

void	render_3d_projection(t_parsing *pars, t_simulation *sim,
		t_player *player)
{
	t_render3d	r;
	int			x;

	r.field_of_view = PI / 3;
	r.half_fov = r.field_of_view / 2;
	r.delta_angle = r.field_of_view / (float)WINDOW_WIDTH;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		r.ray_angle = player->angle - r.half_fov + x * r.delta_angle;
		r.ray_distance = cast_ray_and_return_distance(pars, player, &r);
		r.corrected_distance = r.ray_distance * cos(r.ray_angle
				- player->angle);
		calculate_wall_dimensions(&r);
		render_ceiling_and_floor(x, sim, pars);
		render_wall(&r, sim, x);
		x++;
	}
	mlx_put_image_to_window(sim->mlx_ptr, sim->win_ptr, sim->img->img_ptr, 0,
		0);
}
