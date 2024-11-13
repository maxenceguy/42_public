/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:48:14 by mguy              #+#    #+#             */
/*   Updated: 2024/03/28 10:27:20 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**get_file(char *filename);
int		count_tab_size(t_data *data);
int		count_check(t_data *data);
int		get_map(t_data *data, int ac, char **av);
void	free_tab(t_data *data);

char	**get_file(char *filename)
{
	int		fd;
	char	*tmp;
	char	*ret;

	if (check_ext(filename) == -1)
		return (NULL);
	fd = open(filename, 0);
	ret = malloc(sizeof(char) * 1);
	if (ret == NULL)
		return (close(fd), NULL);
	ret[0] = '\0';
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (close(fd), free(ret), NULL);
	while (tmp)
	{
		ret = ft_strjoin(ret, tmp);
		if (ret == NULL)
			return (close(fd), free(ret), free(tmp), NULL);
		tmp = get_next_line(fd);
	}
	return (close(fd), free(tmp), ft_split(ret, '\n'));
}

int	count_tab_size(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
			x++;
		y++;
	}
	data->map_height = y;
	data->map_width = x;
	return (0);
}

int	count_check(t_data *data)
{
	int	y;
	int	x;

	data->total_check = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				data->total_check++;
			x++;
		}
		y++;
	}
	return (0);
}

int	get_map(t_data *data, int ac, char **av)
{
	(void)ac;
	data->map = get_file(av[1]);
	if (data->map == NULL)
		exit_error(data, "Can't open or read the map\n");
	count_tab_size(data);
	count_check(data);
	if (data->map == NULL)
		return (ft_printf("Error read file\n", -1));
	check_map(data);
	return (0);
}

void	free_tab(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free (data->map);
}
