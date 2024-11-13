/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:56:16 by mguy              #+#    #+#             */
/*   Updated: 2024/10/13 15:47:47 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_parsing(t_parsing *p)
{
	if (p->no)
		free(p->no);
	if (p->so)
		free(p->so);
	if (p->we)
		free(p->we);
	if (p->ea)
		free(p->ea);
	if (p->f)
		free(p->f);
	if (p->c)
		free(p->c);
	free_map_and_file(p);
}

void	free_textures(t_simulation *sim)
{
	if (sim->textures->north && sim->textures->north->img)
		mlx_destroy_image(sim->mlx_ptr, sim->textures->north->img);
	if (sim->textures->south && sim->textures->south->img)
		mlx_destroy_image(sim->mlx_ptr, sim->textures->south->img);
	if (sim->textures->west && sim->textures->west->img)
		mlx_destroy_image(sim->mlx_ptr, sim->textures->west->img);
	if (sim->textures->east && sim->textures->east->img)
		mlx_destroy_image(sim->mlx_ptr, sim->textures->east->img);
	if (sim->textures->north)
		free(sim->textures->north);
	if (sim->textures->south)
		free(sim->textures->south);
	if (sim->textures->west)
		free(sim->textures->west);
	if (sim->textures->east)
		free(sim->textures->east);
	if (sim->textures)
		free(sim->textures);
}

void	free_simulation_second(t_simulation *sim)
{
	if (sim->img)
	{
		if (sim->img->img_ptr)
			mlx_destroy_image(sim->mlx_ptr, sim->img->img_ptr);
		free(sim->img);
	}
	if (sim->win_ptr)
	{
		mlx_destroy_window(sim->mlx_ptr, sim->win_ptr);
	}
	mlx_destroy_display(sim->mlx_ptr);
	if (sim->mlx_ptr)
		free(sim->mlx_ptr);
	if (sim->player)
		free(sim->player);
}

void	free_simulation(t_simulation *sim)
{
	if (sim)
	{
		free_textures(sim);
		free_simulation_second(sim);
		if (sim->keys)
			free(sim->keys);
		free(sim);
	}
}

void	free_all(t_cub3d *cube)
{
	if (cube)
	{
		if (cube->parsing != NULL)
		{
			free_parsing(cube->parsing);
			free(cube->parsing);
		}
		if (cube->simulation != NULL)
			free_simulation(cube->simulation);
		free(cube);
	}
}
