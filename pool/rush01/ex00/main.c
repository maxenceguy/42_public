/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:40:33 by mguy              #+#    #+#             */
/*   Updated: 2023/08/20 20:00:21 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

unsigned int	display_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	free_struct(t_data *data)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		free(data->tab[i]);
		i++;
	}
	free(data->tab);
	free(data->key);
	free(data);
}

int	main(int argc, char **argv)
{
	unsigned int		error;
	t_data				*data;

	error = 0;
	if (argc != 2)
		return (display_error());
	data = malloc(sizeof(t_data));
	if (!data)
		return (display_error());
	error = parser(data, argv);
	if (error == 1)
	{
		free(data);
		return (display_error());
	}
	if (fill_table(data, 0))
		print_table(data);
	else
	{
		free_struct(data);
		return (display_error());
	}
	free_struct(data);
	return (0);
}
