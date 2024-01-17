/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:03:45 by alermolo          #+#    #+#             */
/*   Updated: 2023/08/30 14:32:24 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	get_raw_map(t_bsq *bsq, char *map_name, int to_read)
{
	char	buffer[1024];
	int		read_size;
	int		total_size;

	read_size = 1;
	total_size = 0;
	while (read_size)
	{
		read_size = read(to_read, buffer, 1024);
		total_size += read_size;
	}
	close(to_read);
	to_read = open(map_name, O_RDONLY);
	bsq->raw_map = (char *)malloc(sizeof(char) * total_size + 1);
	if (!bsq->raw_map)
		exit(-1);
	read_size = read(to_read, bsq->raw_map, total_size);
	bsq->raw_map[total_size] = '\0';
}

int	first_line_valid(t_bsq *bsq)
{
	int	len;
	int	i;

	len = ft_strlen(bsq->map[0]);
	if (len < 4)
		return (0);
	i = len - 4;
	while (i >= 0)
	{
		if (bsq->map[0][i] < '0' || bsq->map[0][i] > '9')
			return (0);
		i--;
	}
	if (bsq->map[0][len - 3] < ' ' || bsq->map[0][len - 3] == 127
		|| bsq->map[0][len - 2] < ' ' || bsq->map[0][len - 2] == 127
		|| bsq->map[0][len - 1] < ' ' || bsq->map[0][len - 1] == 127)
		return (0);
	if (bsq->map[0][len - 3] == bsq->map[0][len - 2]
		|| bsq->map[0][len - 2] == bsq->map[0][len - 1]
		|| bsq->map[0][len - 1] == bsq->map[0][len - 3])
		return (0);
	if (!(bsq->map[1][0] != bsq->map[0][len - 3]
		|| bsq->map[1][0] != bsq->map[0][len - 2]))
		return (0);
	return (1);
}

int	map_is_valid(t_bsq *bsq)
{
	int	i;
	int	j;
	int	line_len;

	i = 1;
	line_len = ft_strlen(bsq->map[1]);
	if (bsq->raw_map[ft_strlen(bsq->raw_map) - 1] != '\n')
		return (0);
	while (bsq->map[i])
	{
		if (ft_strlen(bsq->map[i]) != line_len)
			return (0);
		j = 0;
		while (bsq->map[i][j])
		{
			if (!(bsq->map[i][j] == bsq->empty
				|| bsq->map[i][j] == bsq->obst))
				return (0);
			j++;
		}
		i++;
	}
	if (i - 1 != bsq->size)
		return (0);
	return (1);
}

void	convert_map(t_bsq *bsq)
{
	int		i;
	int		j;

	i = 0;
	bsq->val_map = (int **)malloc(sizeof(int *) * bsq->size);
	if (!bsq->val_map)
		exit(-1);
	while (bsq->map[i + 1])
	{
		bsq->val_map[i] = malloc(sizeof(int) * ft_strlen(bsq->map[i + 1]));
		if (!bsq->val_map[i])
			exit(-1);
		j = 0;
		while (bsq->map[i + 1][j])
		{
			if (bsq->map[i + 1][j] == bsq->empty)
				bsq->val_map[i][j] = 1;
			else if (bsq->map[i + 1][j] == bsq->obst)
				bsq->val_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	parse_map(t_bsq *bsq, char *map_name, int ac)
{
	int		to_read;
	int		i;

	if (ac == 1)
		map_name = read_stdin();
	to_read = open(map_name, O_RDONLY);
	if (to_read == -1)
		return (-1);
	get_raw_map(bsq, map_name, to_read);
	close(to_read);
	bsq->map = ft_split(bsq->raw_map, "\n");
	if (!first_line_valid(bsq))
		return (-1);
	bsq->size = 0;
	i = 0;
	while (i < ft_strlen(bsq->map[0]) - 3)
		bsq->size = bsq->size * 10 + (bsq->map[0][i++] - '0');
	bsq->empty = bsq->map[0][ft_strlen(bsq->map[0]) - 3];
	bsq->obst = bsq->map[0][ft_strlen(bsq->map[0]) - 2];
	bsq->fill = bsq->map[0][ft_strlen(bsq->map[0]) - 1];
	if (!map_is_valid(bsq))
		return (-1);
	convert_map(bsq);
	return (1);
}
