/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:35:22 by mguy              #+#    #+#             */
/*   Updated: 2024/03/28 10:27:50 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		check_ext(char *filename);
char	*exit_error(t_data *data, char *mess);
void	destroy_all(t_data *data);

int	check_ext(char *filename)
{
	int		x;
	int		j;
	char	*ext;

	x = 0;
	j = 0;
	ext = malloc(sizeof(char) * ft_strlen(filename));
	if (ext == NULL)
		return (-1);
	while (filename[x] && filename[x] != '.')
		x++;
	if (!filename[x])
		return (free(ext), -1);
	while (filename[x + j])
	{
		ext[j] = filename[x + j];
		j++;
	}
	ext[j] = '\0';
	if (ft_strcmp(ext, ".ber") != 0)
		return (free(ext), -1);
	free(ext);
	return (1);
}

char	*exit_error(t_data *data, char *mess)
{
	if (data->map != NULL)
		free_tab(data);
	ft_printf("%s", mess);
	perror("Error\n");
	exit (1);
}

void	destroy_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->character);
	mlx_destroy_image(data->mlx, data->door_open);
	mlx_destroy_image(data->mlx, data->door_close);
	mlx_destroy_image(data->mlx, data->chest_open);
	mlx_destroy_image(data->mlx, data->chest_close);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
