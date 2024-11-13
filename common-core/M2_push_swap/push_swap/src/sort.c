/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxc <mxc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:15:22 by mxc               #+#    #+#             */
/*   Updated: 2024/02/13 19:03:24 by mxc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	manage_round(t_list **l_a, t_list **l_b, t_param *p)
{
	if (p->global_max < p->max_lb || p->round == 0)
	{
		min_on_top(l_a);
		push_max(l_a, l_b);
	}
	if (p->round != 0 && p->rotate == 2)
		while ((*l_a)->pos != p->max + 1)
			do_r(l_a, "ra\n");
	p->round++;
}

void	push_optimized(t_list **l_a, t_list **l_b, t_param *p)
{
	int	rot;

	p->max = find_min_pos(l_b) - 1;
	while ((*l_b))
	{
		rot = 0;
		push_max(l_a, l_b);
		p->min = find_min_pos(l_b);
		if (find_fast((*l_a)->pos - 1, l_b, get_len(l_b)) == 2)
			rot = 2;
		while ((*l_b) && (*l_b)->pos != (*l_a)->pos - 1)
		{
			push_min(l_a, l_b, p->min);
			if (rot == 2)
				do_rr(l_b, "rrb\n");
			else
				do_r(l_b, "rb\n");
		}
		do_push(l_a, l_b, "pa\n");
	}
	if ((*l_a)->pos > p->max + 1)
		while ((*l_a)->pos != p->max + 1)
			do_rr(l_a, "rra\n");
}

int	sort_a(t_list **l_a, t_list **l_b, t_param *p)
{
	if (get_len(l_a) <= 5)
		return (spe_sort(l_a, l_b), 1);
	while ((*l_a) && p->len_b <= p->max_lb && p->top <= p->len_a)
	{
		if (p->max >= p->max_lb && (*l_a)->pos == p->max + 1
			&& p->top > 2 && p->round > 0 && p->rotate != 2)
			break ;
		if (p->rotate == 2 && (*l_a)->pos == p->global_max && p->round > 0)
		{
			do_r(l_a, "ra\n");
			break ;
		}
		p->len_b = get_len(l_b);
		if (((*l_a)->pos <= p->max && (*l_a)->pos > (p->max - p->max_lb + 1)))
			do_push(l_b, l_a, "pb\n");
		else
		{
			if (p->rotate == 2)
				do_rr(l_a, "rra\n");
			else
				do_r(l_a, "ra\n");
		}
		p->top++;
	}
	return (0);
}

void	sort(t_list **l_a, t_list **l_b)
{
	t_param	p;

	p.max = find_max_pos(l_a);
	p.global_max = p.max;
	p.round = 0;
	p.len_a = get_len(l_a);
	p.max_lb = 35;
	if (p.len_a >= 300)
		p.max_lb = 60;
	while (!verif_sort(l_a))
	{
		p.top = 0;
		p.len_b = get_len(l_b);
		p.rotate = 0;
		if (p.round > 0 && find_fast(p.max + 1, l_a, p.len_a) == 2)
			p.rotate = 2;
		if (sort_a(l_a, l_b, &p) == 1)
			return ;
		manage_round(l_a, l_b, &p);
		push_optimized(l_a, l_b, &p);
	}
}
