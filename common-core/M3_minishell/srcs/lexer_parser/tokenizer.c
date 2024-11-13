/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:33:37 by rolamber          #+#    #+#             */
/*   Updated: 2024/07/24 16:10:53 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>

// create a list of tokens from a string
t_node	*tokenize_command(char *str)
{
	t_node	*last;
	t_node	*node;

	node = get_next_token(str);
	if (!node)
		return (NULL);
	while (node->type != NONE)
	{
		last = node;
		node = get_next_token(str);
		if (!node)
			return (NULL);
		last->next = node;
		node->prev = last;
		node->fd = NULL;
		node->access_error = false;
	}
	while (node->prev)
		node = node->prev;
	return (node);
}

bool	write_here_file(t_gen *gen, int temp_fd, bool flag)
{
	char	*line;

	g_signal = 0;
	while (1)
	{
		rl_event_hook = (void *)breakheredoc;
		line = readline("> ");
		rl_event_hook = NULL;
		if (!line || g_signal != 0)
		{
			gen->canceled_hrdoc = true;
			free(line);
			break ;
		}
		if (ft_strcmp(gen->node->str, line) == 0)
			break ;
		if (flag == true)
			line = heredoc_expand(line, gen);
		if (!line)
			return (false);
		ft_putstr_fd(line, temp_fd);
		ft_putstr_fd("\n", temp_fd);
		free(line);
	}
	return (g_signal == 0);
}

void	create_outfile(t_node *node)
{
	int	temp_fd;

	if (node->type == REDIRECT_OUT)
		temp_fd = open(node->str, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		temp_fd = open(node->str, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (temp_fd < 0)
	{
		perror("open");
		return ;
	}
	node->fd = node->str;
	close(temp_fd);
}

t_command	*head_cmd(t_command *command)
{
	if (!command)
		return (NULL);
	while (command->prev)
		command = command->prev;
	return (command);
}
