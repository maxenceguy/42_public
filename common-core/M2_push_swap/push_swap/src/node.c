/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxc <mxc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 04:37:24 by mguy              #+#    #+#             */
/*   Updated: 2024/02/08 22:42:16 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*new_node(t_list **list_a, int value)
{
	t_list	*new;

	new = malloc(sizeof * new);
	if (!new)
		exit_error(list_a, NULL);
	new->value = value;
	new->pos = -1;
	return (new);
}

t_list	**node_top(t_list **list, t_list *node)
{
	if (!(*list))
	{
		(*list) = node;
		(*list)->next = NULL;
		return (list);
	}
	node->next = (*list);
	*list = node;
	return (list);
}

t_list	**node_bottom(t_list **list, t_list *node)
{
	t_list	*tmp;

	tmp = (*list);
	if (!(*list))
	{
		node->next = NULL;
		(*list) = node;
		return (list);
	}
	while (tmp->next)
		tmp = tmp->next;
	node->next = NULL;
	tmp->next = node;
	return (list);
}
