/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demote_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:48:18 by rolamber          #+#    #+#             */
/*   Updated: 2024/05/09 15:48:18 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdio.h>

char	*meta_to_text(t_token_type type)
{
	if (type == QUOTE)
		return (ft_strdup("\'"));
	else if (type == DOUBLE_QUOTE)
		return (ft_strdup("\""));
	else if (type == REDIRECT_IN)
		return (ft_strdup("<"));
	else if (type == REDIRECT_OUT)
		return (ft_strdup(">"));
	else if (type == APPEND)
		return (ft_strdup(">>"));
	else if (type == HEREDOC)
		return (ft_strdup("<<"));
	else if (type == PIPE)
		return (ft_strdup("|"));
	else if (type == SPACE)
		return (ft_strdup(" "));
	else if (type == TAB)
		return (ft_strdup("\t"));
	else if (type == DOLLAR)
		return (ft_strdup("$"));
	else if (type == LAST_PROCESS_STATUS)
		return (ft_strdup("$?"));
	return (NULL);
}

t_node	*demote_to_next_quote(t_node *node, t_token_type type)
{
	t_node	*first;

	first = node;
	while (node)
	{
		if (node->type == type)
		{
			join_tokens(first, type);
			node = node->next;
			pop_node(node->prev);
			return (node->prev);
		}
		else if (node->type != TEXT && node->type != NONE \
			&& node->type != EXPANDED_TEXT)
		{
			node->str = meta_to_text(node->type);
			if (!node->str)
				return (NULL);
			node->type = TEXT;
		}
		else if (node->type == EXPANDED_TEXT)
			node->type = TEXT;
		node = node->next;
	}
	return (NULL);
}

t_node	*join_tokens(t_node *node, t_token_type delimiter)
{
	char	*temp;

	while (node && node->type != delimiter)
	{
		if (node->next && node->type == TEXT && node->next->type == TEXT)
		{
			temp = node->str;
			node->str = ft_strjoin(node->str, node->next->str);
			free(temp);
			if (!node->str)
				return (NULL);
			pop_node(node->next);
		}
		else
			node = node->next;
	}
	return (head_node(node));
}
// demote all the token quote and double quote

t_node	*demote_tokens(t_node *node)
{
	t_token_type	quote_type;

	while (node->type != NONE)
	{
		if (node->type == QUOTE || node->type == DOUBLE_QUOTE)
		{
			quote_type = node->type;
			node = node->next;
			pop_node(node->prev);
			node = demote_to_next_quote(node, quote_type);
			if (!node)
				return (NULL);
		}
		node = node->next;
	}
	return (head_node(node));
}
