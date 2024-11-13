/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:43:55 by rolamber          #+#    #+#             */
/*   Updated: 2024/06/13 14:43:55 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	count_args(t_node *node)
{
	size_t	i;

	i = 0;
	while (node->type != PIPE && node->type != NONE)
	{
		if (node->type == TEXT)
			i++;
		node = node->next;
	}
	return (i);
}

static char	**add_arg(char *str, char **args)
{
	size_t	i;
	char	*new_arg;

	new_arg = ft_strdup(str);
	if (!new_arg)
		return (NULL);
	i = 0;
	while (args[i])
		i++;
	args[i] = new_arg;
	return (args);
}

static t_command	*tk_to_cmd(t_node *node, t_command *command, char **n_arg)
{
	while (node->type != PIPE && node->type != NONE)
	{
		if (node->access_error == true)
			command->access_error = true;
		else if (node->type == TEXT)
		{
			command->args = add_arg(node->str, n_arg);
			if (!command->args)
				return (NULL);
		}
		else if (node->type == REDIRECT_IN)
			command->fd_in = ft_strdup(node->fd);
		else if (node->type == HEREDOC)
			command->heredoc_file = ft_strdup(node->fd);
		else if (node->type == REDIRECT_OUT || node->type == APPEND)
			command->fd_out = ft_strdup(node->fd);
		if (node->type == APPEND)
			command->append = 1;
		else if (node->type == REDIRECT_OUT)
			command->append = 0;
		node = node->next;
	}
	return (command);
}

static t_command	*token_to_command(t_node *node, t_command *command)
{
	size_t	i;
	char	**new_args;

	command = add_command(command);
	if (!command)
		return (NULL);
	i = count_args(node);
	new_args = (char **)calloc(i + 1, sizeof(char *));
	if (!new_args)
		return (NULL);
	command->args = new_args;
	command = tk_to_cmd(node, command, new_args);
	return (command);
}

int	tokens_to_command(t_node *node, t_gen *gen)
{
	t_node		*current;

	current = node;
	while (node)
	{
		if (node->type == PIPE || node->type == NONE)
		{
			gen->command = token_to_command(current, gen->command);
			if (!gen->command)
				return (-1);
			if (gen->command->access_error == true)
				gen->command = case_acces_error(gen);
			else if (!gen->command->args[0] && node->type == PIPE)
			{
				gen->error_code = 2;
				return (printf("parse error near `|'\n"), -2);
			}
			if (node->type == PIPE && node->next)
				current = node->next;
		}
		node = node->next;
	}
	return (0);
}
