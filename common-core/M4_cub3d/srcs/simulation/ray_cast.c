/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:31:33 by mguy              #+#    #+#             */
/*   Updated: 2024/09/25 12:18:55 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	get_ray_y(t_ray *ray, t_player *player, float ray_dir_y)
{
	if (ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

static void	init_ray_steps(t_player *player, float ray_dir_x, float ray_dir_y,
		t_ray *ray)
{
	ray->delta_dist_x = fabs(1 / ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray_dir_y);
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->ray_x = player->x;
	ray->ray_y = player->y;
	if (ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	get_ray_y(ray, player, ray_dir_y);
}

static int	find_wall_hit(t_parsing *parsing, t_ray *ray, int *side)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			*side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			*side = 1;
		}
		if (parsing->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	return (hit);
}

static float	calculate_distance(t_ray *ray,
		int side, float *hit_x, float *hit_y)
{
	float	distance;

	if (side == 0)
	{
		distance = (ray->map_x - ray->ray_x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
		*hit_y = ray->ray_y + distance * ray->ray_dir_y;
		*hit_x = ray->map_x;
	}
	else
	{
		distance = (ray->map_y - ray->ray_y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
		*hit_x = ray->ray_x + distance * ray->ray_dir_x;
		*hit_y = ray->map_y;
	}
	return (distance);
}

float	cast_ray_and_return_distance(t_parsing *parsing, t_player *player,
		t_render3d *rd)
{
	t_ray	ray;

	ray.ray_dir_x = cos(rd->ray_angle);
	ray.ray_dir_y = sin(rd->ray_angle);
	init_ray_steps(player, ray.ray_dir_x, ray.ray_dir_y, &ray);
	find_wall_hit(parsing, &ray, &rd->side);
	return (calculate_distance(&ray, rd->side, &rd->hit_x, &rd->hit_y));
}
