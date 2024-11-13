/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxc <mxc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:30:09 by mxc               #+#    #+#             */
/*   Updated: 2024/01/31 17:14:17 by mxc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min(t_list **list_a)
{
	t_list	*tmp;
	int		min;

	if (!(*list_a))
		return (0);
	tmp = (*list_a);
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_list **list)
{
	t_list	*tmp;
	int		max;

	if (!(*list))
		return (0);
	tmp = (*list);
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min_pos(t_list **list)
{
	t_list	*tmp;
	int		min;

	if (!(*list))
		return (0);
	tmp = (*list);
	min = tmp->pos;
	while (tmp)
	{
		if (tmp->pos < min)
			min = tmp->pos;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max_pos(t_list **list)
{
	t_list	*tmp;
	int		max;

	if (!(*list))
		return (0);
	tmp = (*list);
	max = tmp->pos;
	while (tmp)
	{
		if (tmp->pos > max)
			max = tmp->pos;
		tmp = tmp->next;
	}
	return (max);
}

int	find_fast(int pos, t_list **list, int len)
{
	t_list	*tmp;
	int		i;

	tmp = (*list);
	i = 0;
	while (tmp && tmp->next && (tmp->pos < pos || tmp->next->pos > pos))
	{
		tmp = tmp->next;
		i++;
	}
	i++;
	if (len / 2 >= i + 1)
		return (1);
	else
		return (2);
}
