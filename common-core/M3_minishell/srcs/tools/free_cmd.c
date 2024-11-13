/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:17:23 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:36:04 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_cmd(t_gen *gen)
{
	t_command	*cmd;

	cmd = gen->command;
	while (cmd)
	{
		if (cmd->args)
			free_tab(cmd->args);
		cmd->args = NULL;
		if (cmd->next)
		{
			cmd = cmd->next;
			pop_cmd(cmd->prev);
		}
		else
		{
			pop_cmd(cmd);
			gen->command = NULL;
			return ;
		}
	}
}

// Free env list 
void	free_list(t_env *head)
{
	t_env	*current;
	t_env	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
}
