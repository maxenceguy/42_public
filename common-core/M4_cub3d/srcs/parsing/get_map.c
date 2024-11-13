/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:27:07 by mguy              #+#    #+#             */
/*   Updated: 2024/09/23 14:48:48 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	allocate_map(t_parsing *p, int file_y)
{
	int	tempy;

	tempy = 0;
	while (p->file[file_y + tempy] && p->file[file_y + tempy][0] != '\n')
		tempy++;
	p->map = malloc(sizeof(char *) * (tempy + 1));
	if (p->map == NULL)
		return (1);
	return (0);
}

int	allocate_map_line(t_parsing *p, int tempy, int line_length)
{
	int	i;

	p->map[tempy] = malloc(sizeof(char) * (line_length + 1));
	if (p->map[tempy] == NULL)
	{
		i = 0;
		while (i < tempy)
		{
			free(p->map[i]);
			i++;
		}
		free(p->map);
		return (1);
	}
	return (0);
}

void	copy_map_line(char *dest, char *src)
{
	int	filex;
	int	mapx;

	mapx = 0;
	filex = 0;
	while (src[filex] != '\n' && src[filex] != '\0')
	{
		dest[mapx] = src[filex];
		mapx++;
		filex++;
	}
	dest[mapx] = '\0';
}

int	fill_map(t_parsing *p, int file_y)
{
	int	tempy;
	int	line_length;

	tempy = 0;
	while (p->file[file_y] && p->file[file_y][0] != '\n')
	{
		line_length = ft_strlen(p->file[file_y]);
		if (allocate_map_line(p, tempy, line_length) != 0)
			return (1);
		copy_map_line(p->map[tempy], p->file[file_y]);
		file_y++;
		tempy++;
	}
	p->map[tempy] = NULL;
	return (0);
}

int	get_map(t_parsing *p)
{
	int	file_y;

	file_y = find_map_start(p->file);
	if (file_y == -1)
		return (1);
	while (p->file[file_y] && p->file[file_y][0] == '\n')
		file_y++;
	if (allocate_map(p, file_y) != 0)
		return (1);
	if (fill_map(p, file_y) != 0)
		return (1);
	return (0);
}
