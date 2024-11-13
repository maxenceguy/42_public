/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:44:59 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:34:19 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Function to open a file descriptor with proper error handling
int	open_file_descriptor(char *file, int flags, int mode, t_gen *gen)
{
	int	fd;

	fd = open(file, flags, mode);
	if (fd < 0)
	{
		perror("Error opening file");
		gen->error_code = 1;
	}
	return (fd);
}

// Function to handle input redirection
int	handle_input_redirection(t_command *cmd, t_command *c, t_gen *gen)
{
	if (cmd->ifd_in > 0)
		close(cmd->ifd_in);
	if (c->heredoc_file)
		cmd->ifd_in = open_file_descriptor(c->heredoc_file, O_RDONLY, 0, gen);
	else if (c->fd_in)
		cmd->ifd_in = open_file_descriptor(c->fd_in, O_RDONLY, 0, gen);
	else
		return (0);
	if (cmd->ifd_in < 0)
		return (-1);
	if (dup2(cmd->ifd_in, STDIN_FILENO) == -1)
	{
		perror("dup2 input");
		gen->error_code = 1;
		return (-1);
	}
	return (0);
}

// Function to handle output redirection
int	handle_output_redirection(t_command *cmd, t_command *current, t_gen *gen)
{
	int	flags;

	if (cmd->ifd_out > 0)
		close(cmd->ifd_out);
	if (current->fd_out)
	{
		if (current->append)
			flags = O_WRONLY | O_CREAT | O_APPEND;
		else
			flags = O_WRONLY | O_CREAT | O_TRUNC;
		cmd->ifd_out = open_file_descriptor(current->fd_out, flags, 0644, gen);
		if (cmd->ifd_out < 0)
			return (-1);
		if (dup2(cmd->ifd_out, STDOUT_FILENO) == -1)
		{
			perror("dup2 output");
			gen->error_code = 1;
			return (-1);
		}
	}
	return (0);
}

// Function to handle all redirections in a command
int	handle_redirections(t_command *cmd, t_gen *gen)
{
	t_command	*current;

	current = cmd;
	cmd->ifd_in = 0;
	cmd->ifd_out = 0;
	while (current)
	{
		if ((current->fd_in || current->heredoc_file)
			&& !is_builtin(current->args[0]))
		{
			if (handle_input_redirection(cmd, current, gen) < 0)
				return (-1);
		}
		if (current->fd_out)
		{
			if (handle_output_redirection(cmd, current, gen) < 0)
				return (-1);
		}
		current = current->next;
	}
	return (0);
}
