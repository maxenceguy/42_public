/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:26:43 by mguy              #+#    #+#             */
/*   Updated: 2024/02/07 13:10:24 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

void	free_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i] != NULL)
		free(args[i]);
	free(args);
}

void	exit_error(t_list **list_a, t_list **list_b)
{
	free_list(list_a);
	free_list(list_b);
	ft_putstr("Error\n", 0);
	exit(1);
}

int	check_params(char **args)
{
	int	y;
	int	i;

	y = 0;
	while (args[y])
	{
		i = 1;
		while (args[y + i])
		{
			if (args[y + i] && ft_strcmp(args[y], args[y + i]) == 0)
				return (0);
			i++;
		}
		if (ft_int_max(args[y]))
			return (0);
		if (ft_int_min(args[y]))
			return (0);
		y++;
	}
	return (1);
}

int	check_int(char *param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		if ((param[i] < 48 || param[i] > 57)
			&& param[i] != '-' && param[i] != '+')
			return (0);
		i++;
	}
	return (1);
}
