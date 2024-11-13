/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:39:51 by rolamber          #+#    #+#             */
/*   Updated: 2024/07/23 16:29:40 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	special_sep_meta(t_node *node)
{
	if (node->type == SPACE || node->type == TAB || node->type == NONE \
	|| node->type == HEREDOC || node->type == PIPE || node->type == REDIRECT_IN \
	|| node->type == REDIRECT_OUT || node->type == APPEND)
		return (true);
	return (false);
}

static t_node	*fusion_heredoc_token(t_node *node)
{
	t_node	*tmp;
	char	*temp;

	tmp = node;
	node = node->next;
	while (node && !special_sep_meta(node->next))
	{
		if (node->next && node->type == TEXT && node->next->type == TEXT)
		{
			temp = node->str;
			node->str = ft_strjoin(node->str, node->next->str);
			if (!node->str)
				return (NULL);
			free(temp);
			pop_node(node->next);
		}
		else
			node = node->next;
	}
	tmp->str = ft_strdup(tmp->next->str);
	if (!tmp->str)
		return (NULL);
	pop_node(tmp->next);
	return (tmp);
}

static t_node	*join_dollar_heredoc(t_node *node)
{
	t_token_type	type;

	while (!special_sep_meta(node))
	{
		if (node->type == QUOTE || node->type == DOUBLE_QUOTE)
		{
			type = node->type;
			node = node->next;
			pop_node(node->prev);
			node = demote_to_next_quote(node, type);
			if (!node)
				return (NULL);
		}
		else if (node->type == DOLLAR || node->type == LAST_PROCESS_STATUS)
		{
			dollar_or_process(node);
			if (!node->str)
				return (NULL);
			node->type = TEXT;
		}
		node = node->next;
	}
	return (node);
}

static t_node	*get_heredoc_token(t_node *node, t_gen *gen)
{
	t_node	*tmp;
	bool	flag;

	flag = true;
	tmp = node;
	node = node->next;
	if (special_sep_meta(node))
		return (printf("minishell : syntax error near unexpected token `%s'\n"\
			, meta_to_text(node->type)), NULL);
	while (node && !special_sep_meta(node))
	{
		if (node->type == QUOTE || node->type == DOUBLE_QUOTE)
			flag = false;
		node = node->next;
	}
	node = join_dollar_heredoc(tmp->next);
	if (!node)
		return (NULL);
	node = fusion_heredoc_token(tmp);
	if (!node)
		return (NULL);
	node = heredoc(node, flag, gen);
	return (node);
}

t_node	*heredoc_parser(t_node *node, t_gen *gen)
{
	t_node	*tmp;

	while (node->type != NONE)
	{
		if (node->type == HEREDOC && !is_in_quote(node, QUOTE) \
			&& !is_in_quote(node, DOUBLE_QUOTE))
		{
			tmp = node;
			node = node->next;
			while (node->type == SPACE)
			{
				node = node->next;
				pop_node(node->prev);
			}
			node = get_heredoc_token(tmp, gen);
			if (!node)
				return (NULL);
		}
		node = node->next;
	}
	return (head_node(node));
}
