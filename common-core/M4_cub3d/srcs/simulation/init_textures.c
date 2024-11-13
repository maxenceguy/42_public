/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:44:05 by mguy              #+#    #+#             */
/*   Updated: 2024/09/22 20:24:50 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_texture	*load_texture(void *mlx_ptr, char *file_path)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->img = mlx_xpm_file_to_image(mlx_ptr, file_path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		free(texture);
		return (NULL);
	}
	texture->pixels_ptr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	return (texture);
}

void	load_all_textures(t_parsing *p, t_simulation *sim)
{
	sim->textures->north = load_texture(sim->mlx_ptr, p->no);
	sim->textures->south = load_texture(sim->mlx_ptr, p->so);
	sim->textures->west = load_texture(sim->mlx_ptr, p->we);
	sim->textures->east = load_texture(sim->mlx_ptr, p->ea);
	if (!sim->textures->north || !sim->textures->south || !sim->textures->west
		|| !sim->textures->east)
	{
		ft_putstr_fd("Error: Failed to load textures\n", 2);
		exit(1);
	}
}

int	get_texture_pixel_color(t_texture *texture, int x, int y)
{
	int	offset;

	offset = (y * texture->line_len) + (x * (texture->bpp / 8));
	return (*(unsigned int *)(texture->pixels_ptr + offset));
}

t_texture	*select_texture(t_simulation *sim, int side)
{
	if (side == 0)
	{
		if (cos(sim->west) > 0)
			return (sim->textures->south);
		else
			return (sim->textures->north);
	}
	else
	{
		if (sin(sim->east) > 0)
			return (sim->textures->west);
		else
			return (sim->textures->east);
	}
}
