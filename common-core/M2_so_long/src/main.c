/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:18:21 by mxc               #+#    #+#             */
/*   Updated: 2024/03/22 11:57:24 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../minilibx/mlx.h"

int	loop_hook(t_data *data);
int	main(int ac, char **av);

int	loop_hook(t_data *data)
{
	events(data);
	return (0);
}

void	game_loop(t_data *data)
{
	while (1)
	{
		mlx_loop_hook(data->mlx, &loop_hook, data);
		mlx_hook(data->win, KeyPress, KeyPressMask, &key_press, data);
		mlx_hook(data->win, 17, 0, &close_win, data);
		mlx_loop(data->mlx);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_printf("2 args please.\n"), 0);
	(void)av;
	(void)ac;
	data.nb_mouv = 0;
	data.check = 0;
	data.map_height = 6;
	data.map_width = 34;
	if (get_map(&data, ac, av) == -1)
		return (0);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (exit_error(&data, "Mlx pointer error.\n"), -1);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Lost");
	if (data.win == NULL)
		return (free(data.mlx), exit_error(&data, "Mlx pointer error.\n"), -1);
	get_env(&data);
	set_initial_offsets(&data);
	draw_map(&data);
	game_loop(&data);
	return (0);
}
