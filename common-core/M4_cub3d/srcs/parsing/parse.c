/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:52:18 by mguy              #+#    #+#             */
/*   Updated: 2024/09/25 09:46:31 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	set_all_null(t_parsing *p)
{
	p->no = NULL;
	p->so = NULL;
	p->we = NULL;
	p->ea = NULL;
	p->f = NULL;
	p->c = NULL;
	p->map = NULL;
	p->file = NULL;
}

int	parse_file(t_parsing *p)
{
	p->after = 0;
	p->no = get_textures(p, "NO");
	if (p->no == NULL)
		return (printf("Error parsing NO\n"), 1);
	p->so = get_textures(p, "SO");
	if (p->so == NULL)
		return (printf("Error parsing SO\n"), 1);
	p->we = get_textures(p, "WE");
	if (p->we == NULL)
		return (printf("Error parsing WE\n"), 1);
	p->ea = get_textures(p, "EA");
	if (p->ea == NULL)
		return (printf("Error parsing EA\n"), 1);
	p->f = get_rgb(get_textures(p, "F"));
	if (p->f == NULL)
		return (printf("Error parsing F\n"), 1);
	p->c = get_rgb(get_textures(p, "C"));
	if (p->c == NULL)
		return (printf("Error parsing C\n"), 1);
	if (get_map(p) == 1)
		return (printf("Error parsing map\n"), 1);
	if (!p->map[0][0])
		return (printf("Error parsing map\n"), 1);
	return (0);
}

int	parse(t_cub3d *cube, int ac, char **av)
{
	t_parsing	*p;
	char		*dot;

	(void)ac;
	(void)av;
	if (ac != 2)
		return (printf("1 argument : map name\n"), 1);
	cube->parsing = NULL;
	dot = ft_strrchr(av[1], '.');
	if (ac != 2 || !dot || dot == av[1] || ft_strcmp(dot, ".cub") != 0)
		return (printf("arguments : map_name\n"), 1);
	cube->parsing = malloc(sizeof(t_parsing));
	if (cube->parsing == NULL)
		return (1);
	p = cube->parsing;
	set_all_null(p);
	if (get_file(p, av))
		return (1);
	if (parse_file(p))
		return (1);
	if (check_validity(p))
		return (1);
	return (0);
}
