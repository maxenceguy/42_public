/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_command_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:00 by rolamber          #+#    #+#             */
/*   Updated: 2024/06/14 17:34:00 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_command	*add_command(t_command *command)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	if (!new)
		return (NULL);
	new->args = NULL;
	new->fd_in = NULL;
	new->fd_out = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->heredoc_file = NULL;
	new->access_error = false;
	new->error_code = 0;
	if (!command)
		return (new);
	command->next = new;
	new->prev = command;
	return (new);
}

t_node	*go_to_last(t_node *node)
{
	while (node->type != NONE)
		node = node->next;
	return (node);
}

int	lexer_parser(t_gen *gen, char *line)
{
	t_node		*node;
	t_node		*last;
	int			result;

	node = tokenize_command(line);
	last = go_to_last(node);
	result = lexer(node, gen, last);
	if (result == 1)
		return (1);
	node = head_node(last);
	result = tokens_to_command(node, gen);
	gen->command = head_cmd(gen->command);
	if (result == -1)
		return (free_all_node(head_node(last)), printf("malloc failed\n"), 1);
	else if (result == -2)
		return (free_all_node(head_node(last)), 1);
	free_all_node(node);
	return (0);
}

// return a boolean if the node is in the last inclusion from type 

bool	check_quotes(t_node *node, t_token_type type, t_node *end)
{
	t_token_type	quote_type;

	quote_type = NONE;
	while (node != end)
	{
		if (node->type == QUOTE && quote_type == NONE)
			quote_type = QUOTE;
		else if (node->type == DOUBLE_QUOTE && quote_type == NONE)
			quote_type = DOUBLE_QUOTE;
		else if (node->type == quote_type)
			quote_type = NONE;
		node = node->next;
	}
	return (quote_type == type);
}

bool	is_in_quote(t_node *node, t_token_type type)
{
	t_node	*tmp;

	tmp = node;
	while (node->prev)
		node = node->prev;
	if (!check_quotes(node, type, tmp))
		return (false);
	return (check_quotes(tmp, type, NULL));
}
