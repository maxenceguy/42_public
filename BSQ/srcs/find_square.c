/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:56:24 by mguy              #+#    #+#             */
/*   Updated: 2023/08/30 12:26:41 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	add_min(t_bsq *bsq, int y, int i)
{
	int	min;

	min = bsq->val_map[y][i - 1];
	if (min > bsq->val_map[y - 1][i - 1])
		min = bsq->val_map[y - 1][i - 1];
	if (min > bsq->val_map[y - 1][i])
		min = bsq->val_map[y -1][i];
	return (min);
}

void	new_max(t_bsq *bsq, int y, int x)
{
	bsq->int_max = bsq->val_map[y][x];
	bsq->y_max = y;
	bsq->x_max = x;
}

int	find_max(t_bsq *bsq)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	x = 0;
	len = ft_strlen(bsq->map[1]);
	bsq->int_max = 0;
	while (y < bsq->size)
	{
		while (x < len)
		{
			if (bsq->val_map[y][x] == 1)
			{
				if (y != 0 && x != 0)
					bsq->val_map[y][x] += add_min(bsq, y, x);
				if (bsq->val_map[y][x] > bsq->int_max)
					new_max(bsq, y, x);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	add_cross(t_bsq *bsq)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < bsq->int_max)
	{
		while (x < bsq->int_max)
		{
			bsq->map[bsq->y_max - y + 1][bsq->x_max - x] = bsq->fill;
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	find_square(t_bsq *bsq)
{
	find_max(bsq);
	add_cross(bsq);
	return (0);
}
