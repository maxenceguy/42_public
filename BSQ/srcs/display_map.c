/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:00:22 by mguy              #+#    #+#             */
/*   Updated: 2023/08/30 11:32:25 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	display_map(t_bsq *bsq)
{
	int	y;
	int	line_len;

	y = 1;
	line_len = ft_strlen(bsq->map[y]);
	while (bsq->map[y] != NULL)
	{
		write(1, bsq->map[y], line_len);
		write(1, "\n", 1);
		y++;
	}
}
