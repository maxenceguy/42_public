/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:54:30 by mguy              #+#    #+#             */
/*   Updated: 2024/09/23 02:27:31 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	pimped_cast(float num)
{
	return ((int)(num + 0.5));
}

int	calculate_tile_size(int window_width, int window_height, int map_width,
		int map_height)
{
	return (fmin(window_width / map_width, window_height / map_height));
}

void	my_pixel_put_rgb(int x, int y, t_img *img, int color[3])
{
	int				offset;
	unsigned int	final_color;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	final_color = (color[0] << 16) | (color[1] << 8) | color[2];
	*(unsigned int *)(img->pixels_ptr + offset) = final_color;
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
