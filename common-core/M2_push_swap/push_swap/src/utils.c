/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxc <mxc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:12:53 by mguy              #+#    #+#             */
/*   Updated: 2024/02/08 16:04:55 by mxc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**get_params(int ac, char **av)
{
	char	**args;
	int		i;

	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
	}
	else
	{
		args = malloc(sizeof(char *) * (ac));
		i = 1;
		while (i < ac)
		{
			args[i - 1] = ft_strdup(av[i]);
			i++;
		}
		args[ac - 1] = NULL;
	}
	return (args);
}

t_list	*get_list(int ac, char **av)
{
	t_list		*list_a;
	int			i;
	long int	nb;
	char		**args;

	list_a = NULL;
	i = 0;
	nb = 0;
	args = get_params(ac, av);
	if (!check_params(args))
	{
		free_args(args);
		exit_error(&list_a, NULL);
	}
	while (args[i])
	{
		if (!check_int(args[i]))
			exit_error(&list_a, NULL);
		nb = ft_atoi(args[i]);
		node_bottom(&list_a, new_node(&list_a, (nb)));
		i++;
	}
	free_args(args);
	return (list_a);
}

int	bottom_value(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->value);
}

int	bottom_pos(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->pos);
}

int	verif_sort(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
