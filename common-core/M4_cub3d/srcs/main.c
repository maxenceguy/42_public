/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:18:46 by mguy              #+#    #+#             */
/*   Updated: 2024/10/13 15:58:22 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	print_tab(char **tab)
{
	int	i;

	printf("PRINT_TAB\n");
	i = 0;
	while (tab[i])
	{
		printf("  |%s|\n", tab[i]);
		i++;
	}
}

int	close_window(t_cub3d *cube3d)
{
	free_all(cube3d);
	exit(0);
	return (0);
}

void	handle_events(t_cub3d *cube3d)
{
	mlx_hook(cube3d->simulation->win_ptr, 2, 1L << 0, key_press, cube3d);
	mlx_hook(cube3d->simulation->win_ptr, 3, 1L << 1, key_release, cube3d);
	mlx_hook(cube3d->simulation->win_ptr, 17, 0L, close_window, cube3d);
	mlx_loop_hook(cube3d->simulation->mlx_ptr, handle_player_movement, cube3d);
	mlx_loop(cube3d->simulation->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_cub3d	*cube3d;

	cube3d = init_cub3d(ac, av);
	if (cube3d == NULL)
		return (1);
	if (init_window_and_image(cube3d))
		return (1);
	draw_map(cube3d->simulation, cube3d->parsing);
	mlx_put_image_to_window(cube3d->simulation->mlx_ptr,
		cube3d->simulation->win_ptr, cube3d->simulation->img->img_ptr, 0, 0);
	redraw(cube3d);
	handle_events(cube3d);
	free_all(cube3d);
	return (0);
}
