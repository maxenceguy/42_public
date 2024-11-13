/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joiner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:32:11 by rolamber          #+#    #+#             */
/*   Updated: 2024/06/20 13:32:11 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_text_sep_space(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] && ptr[i] != ' ')
		i++;
	return (ft_substr(ptr, 0, i));
}

static t_node	*add_node(t_node *node, t_token_type type, char *str)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	if (str)
		new_node->str = str;
	else
		new_node->str = NULL;
	new_node->next = node->next;
	new_node->prev = node;
	if (node->next)
		node->next->prev = new_node;
	node->next = new_node;
	new_node->access_error = false;
	new_node->fd = NULL;
	return (new_node);
}

t_node	*split_expanded_text(t_node *node)
{
	int		i;
	char	*arg;
	t_node	*current;

	arg = node->str;
	current = node;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
		{
			node = add_node(node, SPACE, NULL);
			while (arg[i] == ' ')
				i++;
		}
		if (arg[i] && arg[i] != ' ')
		{
			node = add_node(node, TEXT, get_text_sep_space(&arg[i]));
			while (arg[i] && arg[i] != ' ')
				i++;
		}
	}
	pop_node(current);
	return (node);
}

t_node	*transform_expanded_text(t_node *node)
{
	while (node->type != NONE)
	{
		if (node->type == EXPANDED_TEXT)
			node = split_expanded_text(node);
		node = node->next;
	}
	return (head_node(node));
}

t_node	*joiner(t_node *node)
{
	node = transform_expanded_text(node);
	node = join_tokens(node, NONE);
	return (node);
}
