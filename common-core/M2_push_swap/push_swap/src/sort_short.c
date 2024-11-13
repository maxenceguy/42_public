/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxc <mxc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:07:43 by mguy              #+#    #+#             */
/*   Updated: 2024/02/13 19:03:15 by mxc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_list **list, char ab)
{
	if (ab == 'a')
	{
		if ((*list)->value > (*list)->next->value
			&& (*list)->value > (*list)->next->next->value)
			do_r(list, "ra\n");
		else if (bottom_value(list) < (*list)->value
			|| (bottom_value(list) < (*list)->next->value))
			do_rr(list, "rra\n");
		if ((*list)->next->value < (*list)->value)
			do_s(list, "sa\n");
	}
	if (ab == 'b')
	{
		if ((*list)->value > (*list)->next->value
			&& (*list)->value > (*list)->next->next->value)
			do_r(list, "rb\n");
		else if (bottom_value(list) < (*list)->value
			|| (bottom_value(list) < (*list)->next->value))
			do_rr(list, "rrb\n");
		if ((*list)->next->value < (*list)->value)
			do_s(list, "sb\n");
	}
}

int	is_pos_sup(int bot_a, t_list **l_b)
{
	t_list	*tmp;

	tmp = (*l_b);
	while (tmp)
	{
		if (tmp->pos == bot_a + 1)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

void	push_in_b(t_list **l_a, t_list **l_b)
{
	while (!verif_sort(l_a) || (*l_b))
	{
		if (!(*l_b))
			return (min_on_top(l_a));
		if ((*l_b) && (*l_b)->next && ((*l_b)->next->pos == (*l_a)->pos - 1
				|| ((*l_b)->next->pos == 4
					&& (*l_a)->pos == find_min_pos(l_a))))
			do_s(l_b, "sb\n");
		if ((*l_b) && ((bottom_pos(l_a) == (*l_b)->pos - 1)
				|| (*l_a)->pos == (*l_b)->pos + 1
				|| ((*l_b)->pos == 4
					&& (*l_a)->pos == find_min_pos(l_a))))
			do_push(l_a, l_b, "pa\n");
		else if ((*l_a)->pos == bottom_pos(l_a) + 1)
			do_rr(l_a, "rra\n");
		else if (is_pos_sup(bottom_pos(l_a), l_b))
			do_r(l_b, "rb\n");
		else
			do_rr(l_a, "rra\n");
	}
}

void	spe_sort(t_list **l_a, t_list **l_b)
{
	while (!verif_sort(l_a) && get_len(l_a) > 3)
	{
		if ((*l_b) && bottom_pos(l_a) + 1 == (*l_b)->pos)
			do_push(l_a, l_b, "pa\n");
		else if ((bottom_pos(l_a) + 1 == (*l_a)->next->pos
				&& (*l_a)->pos == (*l_a)->next->pos - 1)
			|| (*l_a)->pos < (*l_a)->next->pos)
			do_s(l_a, "sa\n");
		else if ((*l_a)->pos == find_min_pos(l_a)
			|| (*l_a)->pos == bottom_pos(l_a) + 1)
			do_r(l_a, "ra\n");
		else
			do_push(l_b, l_a, "pb\n");
	}
	sort_three(l_a, 'a');
	push_in_b(l_a, l_b);
}
