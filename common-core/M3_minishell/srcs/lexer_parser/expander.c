/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:07:58 by rolamber          #+#    #+#             */
/*   Updated: 2024/07/25 16:34:42 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdio.h>

// check if the node is a special meta
static	bool	is_special_meta(t_node *node)
{
	if (node->type == SPACE || node->type == TAB \
		|| node->type == NONE || node->type == REDIRECT_IN \
		|| node->type == REDIRECT_OUT || node->type == APPEND \
		|| node->type == HEREDOC || node->type == PIPE \
		|| node->type == DOLLAR)
		return (true);
	return (false);
}

static void	expand_last_process(t_node *node, t_gen *gen)
{
	char	*code;

	if (g_signal == 130 || g_signal == 127)
	{
		code = ft_itoa(g_signal);
		g_signal = 0;
	}
	else
		code = ft_itoa(gen->error_code);
	node->type = TEXT;
	node->str = ft_strdup(code);
}

// line 43 : quote ou double quote juxtaposee au dollar
static t_node	*expand_token(t_node *node, t_gen *gen)
{
	char	*expanded;

	if (node->str == NULL)
		return (node);
	expanded = ft_getenv(gen->env, node->str);
	free(node->str);
	if (expanded)
	{
		node->str = ft_strdup(expanded);
		if (!node->str)
			return (NULL);
		node->type = EXPANDED_TEXT;
	}
	return (node);
}

// expand env variables
// line 71: si c'est un token texte ou un token quote
// line 75 : quote ou dquote ca expand pas
t_node	*expand_command(t_node *node, t_gen *gen)
{
	while (node->type != NONE)
	{
		if (node->type == DOLLAR)
		{
			if (is_special_meta(node->next) || is_in_quote(node, QUOTE))
			{
				node->type = TEXT;
				node->str = ft_strdup("$");
				if (!node->str)
					return (NULL);
			}
			else
			{
				node = node->next;
				pop_node(node->prev);
				node = expand_token(node, gen);
				if (!node)
					return (NULL);
			}
		}
		else if (node->type == LAST_PROCESS_STATUS && !is_in_quote(node, QUOTE))
			expand_last_process(node, gen);
		node = node->next;
	}
	return (head_node(node));
}
