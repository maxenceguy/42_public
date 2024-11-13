/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:41:14 by mguy              #+#    #+#             */
/*   Updated: 2024/09/26 16:41:42 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_map_and_file(t_parsing *p)
{
	int	i;

	if (p->map)
	{
		i = 0;
		while (p->map[i])
			free(p->map[i++]);
		free(p->map);
	}
	if (p->file)
	{
		i = 0;
		while (p->file[i])
			free(p->file[i++]);
		free(p->file);
	}
}
