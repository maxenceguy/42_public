/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:07:39 by mguy              #+#    #+#             */
/*   Updated: 2024/09/25 09:44:01 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	find_indent(char *file, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		if (file[i] == to_find[j])
		{
			while (to_find[j] && file[i + j] && file[i + j] == to_find[j])
				j++;
			if (!to_find[j] && file[i + j] == ' ')
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*get_next_part(char *file, int i)
{
	int		y;
	int		r;
	char	*ret;

	i += 2;
	while (file[i] && (file[i] == ' '))
		i++;
	if (file[i] == '\n')
		return (NULL);
	y = i;
	while (file[y] && file[y] != '\n')
		y++;
	ret = malloc(sizeof(char) * (y - i + 1));
	if (ret == NULL)
		return (NULL);
	r = 0;
	while (i < y)
	{
		ret[r] = file[i];
		i++;
		r++;
	}
	ret[r] = '\0';
	return (ret);
}

int	find_map_start(char **file)
{
	int	y;
	int	x;

	y = 0;
	while (file[y])
	{
		x = 0;
		if (file[y][0] == ' ')
		{
			while (file[y][x] == ' ')
				x++;
			if (file[y][x] == '1' || file[y][x] == '0')
				return (y);
		}
		y++;
	}
	return (-1);
}
