/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:11 by mxc               #+#    #+#             */
/*   Updated: 2024/02/09 13:04:18 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_len(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = (*list);
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	min_on_top(t_list **list)
{
	int	min;

	min = find_min_pos(list);
	if (!(*list))
		return ;
	if ((*list)->pos != min)
	{
		if (find_fast(min, list, get_len(list)) == 1)
		{
			while ((*list)->pos != min)
				do_r(list, "ra\n");
		}
		else if (find_fast(min, list, get_len(list)) == 2)
		{
			while ((*list)->pos != min)
				do_rr(list, "rra\n");
		}
	}
}

void	push_min(t_list **l_a, t_list **l_b, int min)
{
	if ((*l_b)->pos == min)
	{
		do_push(l_a, l_b, "pa\n");
		do_r(l_a, "ra\n");
	}
}

void	print_list(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp == NULL)
	{
		ft_printf("NULL");
		return ;
	}
	while (tmp != NULL)
	{
		ft_printf("%i\n", tmp->pos);
		tmp = tmp->next;
	}
}
