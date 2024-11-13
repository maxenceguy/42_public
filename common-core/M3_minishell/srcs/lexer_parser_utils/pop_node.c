/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:20:40 by rolamber          #+#    #+#             */
/*   Updated: 2024/07/25 15:32:09 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>

void	pop_node(t_node *node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node->str)
		free(node->str);
	if (node->fd && node->type == HEREDOC)
		free(node->fd);
	free(node);
}

t_node	*head_node(t_node *node)
{
	while (node->prev)
		node = node->prev;
	return (node);
}

void	free_all_node(t_node *node)
{
	while (node->next)
	{
		node = node->next;
		pop_node(node->prev);
	}
	pop_node(node);
}

void	pop_cmd(t_command *command)
{
	if (command->prev)
		command->prev->next = command->next;
	if (command->next)
		command->next->prev = command->prev;
	if (command->args)
		free_tab(command->args);
	if (command->fd_in)
		free(command->fd_in);
	if (command->fd_out)
		free(command->fd_out);
	if (command->heredoc_file)
	{
		unlink(command->heredoc_file);
		free(command->heredoc_file);
	}
	free(command);
}

void	dollar_or_process(t_node *node)
{
	if (node->type == DOLLAR)
		node->str = ft_strdup("$");
	else
		node->str = ft_strdup("$?");
}
