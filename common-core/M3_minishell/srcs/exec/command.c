/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:07:31 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:40:05 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	count_pipes(t_pipes *pipes, t_gen *gen)
{
	t_command	*current;
	int			num_cmds;

	num_cmds = 0;
	current = gen->command;
	while (current != NULL)
	{
		num_cmds++;
		current = current->next;
	}
	pipes->num_cmds = num_cmds;
}

void	child_process(t_pipes *pipes, t_gen *gen, int i)
{
	signal(SIGINT, SIG_DFL);
	if (i > 0)
	{
		if (dup2(pipes->prev_fd, STDIN_FILENO) == -1)
			display_exit(1, "dup2 input", gen);
		close(pipes->prev_fd);
	}
	if (i < pipes->num_cmds - 1)
	{
		close(pipes->pipe_fds[0]);
		if (dup2(pipes->pipe_fds[1], STDOUT_FILENO) == -1)
			display_exit(1, "dup2 output", gen);
		close(pipes->pipe_fds[1]);
	}
	if (handle_redirections(pipes->current, gen) < 0)
		ft_exit(gen);
	if (is_builtin(pipes->current->args[0]))
	{
		run_builtin(pipes->current, gen);
		ft_exit(gen);
	}
	else
		exec_command(pipes->current, gen);
}

void	parent_process(t_pipes *pipes, t_gen *gen, int i)
{
	(void) gen;
	signal(SIGINT, SIG_IGN);
	if (i > 0)
		close(pipes->prev_fd);
	if (i < pipes->num_cmds - 1)
	{
		close(pipes->pipe_fds[1]);
		pipes->prev_fd = pipes->pipe_fds[0];
	}
	else
	{
		close(pipes->pipe_fds[0]);
		close(pipes->pipe_fds[1]);
	}
	if (pipes->current != NULL && is_builtin2(pipes->current->args[0])
		&& i == pipes->num_cmds - 1)
	{
		if (handle_redirections(pipes->current, gen) < 0)
			display_exit(EXIT_FAILURE, "handle_redirections failed", gen);
		run_builtin2(pipes->current, gen);
	}
	pipes->current = pipes->current->next;
}

void	loop(t_pipes *pipes, t_gen *gen, int i)
{
	if (ft_strcmp(pipes->current->args[0], "exit") == 0)
		display_exit(EXIT_SUCCESS, "exit", gen);
	if (pipe(pipes->pipe_fds) == -1)
		display_exit(EXIT_FAILURE, "pipe failed", gen);
	pipes->pid = fork();
	if (pipes->pid == -1)
		display_exit(EXIT_FAILURE, "fork failed", gen);
	if (pipes->pid == 0)
		child_process(pipes, gen, i);
	else
		parent_process(pipes, gen, i);
}

void	execute_commands(t_gen *gen)
{
	t_pipes	spipes;
	int		i;
	int		status;
	int		pid;

	gen->stdin_fd = dup(STDIN_FILENO);
	gen->stdout_fd = dup(STDOUT_FILENO);
	spipes.cmd = gen->command;
	spipes.current = gen->command;
	spipes.prev_fd = -1;
	count_pipes(&spipes, gen);
	i = -1;
	while (++i < spipes.num_cmds)
	{
		loop(&spipes, gen, i);
	}
	pid = wait(&status);
	while (pid > 0)
		pid = wait(&status);
	dup2(gen->stdin_fd, STDIN_FILENO);
	dup2(gen->stdout_fd, STDOUT_FILENO);
	close(gen->stdin_fd);
	close(gen->stdout_fd);
	signal(SIGINT, &handler);
}
