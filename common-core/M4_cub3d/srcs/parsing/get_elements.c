/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:59:09 by mguy              #+#    #+#             */
/*   Updated: 2024/09/23 16:15:26 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	get_file(t_parsing *p, char **av)
{
	char	*str;
	int		i;
	int		fd;

	str = NULL;
	i = 0;
	fd = open(av[1], O_RDONLY, 0);
	if (fd < 0)
		return (1);
	p->file = malloc(sizeof(char *) * 1024);
	if (p->file == NULL)
		return (1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		p->file[i] = malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (p->file[i] == NULL)
			return (1);
		ft_strcpy(p->file[i], str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	p->file[i] = str;
	return (0);
}

int	*allocate_rgb_array(char *str)
{
	int	*ret;

	ret = malloc(sizeof(int) * 3);
	if (ret == NULL)
	{
		free(str);
		return (NULL);
	}
	return (ret);
}

int	extract_next_number(char *str, int *i)
{
	char	*tmp;
	int		y;
	int		number;

	tmp = malloc(sizeof(char) * 4);
	if (tmp == NULL)
		return (-1);
	y = 0;
	while (ft_isdigit(str[*i]) && y < 3)
	{
		tmp[y] = str[*i];
		y++;
		(*i)++;
	}
	tmp[y] = '\0';
	number = ft_atoi(tmp);
	free(tmp);
	return (number);
}

int	*get_rgb(char *str)
{
	int	i;
	int	round;
	int	*ret;

	i = 0;
	round = 0;
	ret = allocate_rgb_array(str);
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (round < 3)
				ret[round] = extract_next_number(str, &i);
			if (ret[round] == -1)
				return (free(ret), free(str), NULL);
			round++;
		}
		else
			i++;
	}
	if (round != 3)
		return (free(ret), free(str), NULL);
	return (free(str), ret);
}

char	*get_textures(t_parsing *p, char *cardinal_point)
{
	int		i;
	int		line;
	char	*ret;

	line = 0;
	while (p->file[line])
	{
		i = find_indent(p->file[line], cardinal_point);
		if (i != -1)
		{
			p->after = line;
			ret = get_next_part(p->file[line], i);
			if (ret != NULL)
				return (ret);
		}
		line++;
	}
	return (NULL);
}
