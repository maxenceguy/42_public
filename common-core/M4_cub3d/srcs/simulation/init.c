/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:42:03 by mguy              #+#    #+#             */
/*   Updated: 2024/10/13 15:52:35 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cub3d	*init_cub3d(int ac, char **av)
{
	t_cub3d	*c;

	c = malloc(sizeof(t_cub3d));
	if (c == NULL)
		return (NULL);
	if (parse(c, ac, av))
		return (free_parsing(c->parsing), free(c->parsing), free(c), NULL);
	c->simulation = ft_calloc(1, sizeof(t_simulation));
	if (c->simulation == NULL)
		return (free_all(c), NULL);
	c->simulation->img = malloc(sizeof(t_img));
	if (c->simulation->img == NULL)
		return (free(c->simulation), free_all(c), NULL);
	c->simulation->player = malloc(sizeof(t_player));
	if (c->simulation->player == NULL)
		return (free(c->simulation), free(c->simulation->img),
			free_all(c), NULL);
	c->simulation->textures = malloc(sizeof(t_textures));
	if (!c->simulation->textures)
		return (printf("Error: Failed to allocate textures memories\n"), NULL);
	c->simulation->nord = 0.0;
	c->simulation->east = M_PI / 2.0;
	c->simulation->south = M_PI;
	c->simulation->west = 3.0 * M_PI / 2;
	return (c);
}

int	find_tile_size(t_parsing *p)
{
	int	y;
	int	x;
	int	ymax;
	int	xmax;

	ymax = 0;
	xmax = 0;
	y = 0;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x])
		{
			if (y > ymax)
				ymax = y;
			if (x > xmax)
				xmax = x;
			x++;
		}
		y++;
	}
	if (ymax > xmax)
		return (WINDOW_HEIGHT / (3 * ymax));
	else
		return (WINDOW_WIDTH / (3 * xmax));
}

void	load_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->d = 0;
	keys->s = 0;
	keys->left = 0;
	keys->left = 0;
}

int	init_window_and_image(t_cub3d *c)
{
	c->simulation->mlx_ptr = mlx_init();
	if (c->simulation->mlx_ptr == NULL)
		return (free_all(c), 1);
	c->simulation->tile_size = find_tile_size(c->parsing);
	c->simulation->win_ptr = mlx_new_window(c->simulation->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (c->simulation->win_ptr == NULL)
		return (free_all(c), 1);
	c->simulation->img->img_ptr = mlx_new_image(c->simulation->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	c->simulation->img->pixels_ptr = mlx_get_data_addr(
			c->simulation->img->img_ptr,
			&c->simulation->img->bpp, &c->simulation->img->line_len,
			&c->simulation->img->endian);
	load_all_textures(c->parsing, c->simulation);
	c->simulation->keys = malloc(sizeof(t_keys));
	if (!c->simulation->keys)
		return (1);
	ft_memset(c->simulation->keys, 0, sizeof(t_keys));
	return (0);
}
