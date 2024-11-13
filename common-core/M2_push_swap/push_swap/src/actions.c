/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 06:42:56 by mguy              #+#    #+#             */
/*   Updated: 2024/02/07 13:13:32 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_r(t_list **list, char *txt)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*list) || !(*list)->next)
		return ;
	ft_putstr(txt, 0);
	tmp = (*list);
	(*list) = (*list)->next;
	tmp2 = (*list);
	tmp->next = NULL;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
}

void	do_rr(t_list **list, char *txt)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*list) || !(*list)->next)
		return ;
	ft_putstr(txt, 0);
	tmp = (*list);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = (*list);
	(*list) = tmp2;
}

void	do_push(t_list **dest, t_list **src, char *txt)
{
	t_list	*tmp;

	if ((*src) == NULL)
		return ;
	ft_putstr(txt, 0);
	tmp = (*src);
	if (tmp->next == NULL)
		(*src) = NULL;
	else
		(*src) = tmp->next;
	dest = node_top(dest, tmp);
}

void	do_s(t_list **list, char *txt)
{
	t_list	*tmp;

	ft_putstr(txt, 0);
	tmp = (*list);
	(*list) = tmp->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
}

void	push_max(t_list **l_a, t_list **l_b)
{
	int	max_list;
	int	len;

	max_list = find_max_pos(l_b);
	len = get_len(l_b);
	if (!(*l_b))
		return ;
	else if (!(*l_b)->next)
		do_push(l_a, l_b, "pa\n");
	else
	{
		if (find_fast(max_list, l_b, len) == 1)
			while ((*l_b)->pos != max_list)
				do_r(l_b, "rb\n");
		else if (find_fast(max_list, l_b, len) == 2)
			while ((*l_b)->pos != max_list)
				do_rr(l_b, "rrb\n");
		do_push(l_a, l_b, "pa\n");
	}
}
