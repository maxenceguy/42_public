/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_command_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:40:51 by rolamber          #+#    #+#             */
/*   Updated: 2024/07/24 18:31:59 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unlink_all(t_node *node)
{
	while (node->type != NONE)
	{
		if (node->fd)
			unlink(node->fd);
		node = node->next;
	}
}

t_command	*case_acces_error(t_gen *gen)
{
	if (!gen->command->prev)
	{
		pop_cmd(gen->command);
		gen->command = NULL;
	}
	else
	{
		gen->command = gen->command->prev;
		pop_cmd(gen->command->next);
	}
	gen->error_code = 1;
	return (gen->command);
}

int	lexer(t_node *node, t_gen *gen, t_node *last)
{
	node = heredoc_parser(node, gen);
	if (!node && !gen->canceled_hrdoc)
		return (free_all_node(head_node(last)), printf("Error\n"), 1);
	else if (gen->canceled_hrdoc == true)
	{
		gen->canceled_hrdoc = false;
		unlink_all(head_node(last));
		return (free_all_node(head_node(last)), 1);
	}
	node = expand_command(node, gen);
	if (!node)
		return (free_all_node(head_node(last)), printf("Error\n"), 1);
	node = demote_tokens(node);
	if (!node)
		return (free_all_node(head_node(last)), printf("Error\n"), 1);
	node = redirection_parser(node);
	if (!node)
		return (free_all_node(head_node(last)), printf("Error\n"), 1);
	node = joiner(node);
	if (!node)
		return (free_all_node(head_node(last)), printf("Error\n"), 1);
	return (0);
}
