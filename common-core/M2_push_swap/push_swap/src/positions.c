/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:04:34 by mguy              #+#    #+#             */
/*   Updated: 2024/02/09 13:06:56 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max_empty_pos(t_list **list)
{
	t_list	*tmp;
	int		max;
	int		i;
	int		ret;

	max = INT_MIN;
	i = -1;
	ret = 0;
	tmp = (*list);
	while (tmp)
	{
		i++;
		if (tmp->value >= max && tmp->pos == -1)
		{
			max = tmp->value;
			ret = i;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	get_pos(t_list **list)
{
	t_list	*tmp;
	int		len;
	int		max;
	int		i;
	int		y;

	y = 0;
	len = get_len(list);
	while (y < len)
	{
		i = 0;
		max = find_max_empty_pos(list);
		tmp = (*list);
		while (i < max && tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		tmp->pos = len - y - 1;
		y++;
	}
}
