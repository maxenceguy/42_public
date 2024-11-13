/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:10:58 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:07:27 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_from_path(t_command *cmd, char **t_env, t_gen *gen)
{
	char	*env_path;
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	env_path = ft_getenv(gen->env, "PATH");
	if (env_path == NULL)
		env_path = "/bin:/usr/bin";
	paths = ft_split(env_path, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, cmd->args[0]);
		free(path);
		execve(full_path, cmd->args, t_env);
		free(full_path);
		i++;
	}
	ft_split_free(paths);
	perror("execve");
	error_exit(127, gen);
}

void	exec_absolute_or_relative_path(t_command *cmd, char **t_env, t_gen *gen)
{
	execve(cmd->args[0], cmd->args, t_env);
	perror("execve");
	free(t_env);
	error_exit(127, gen);
}

int	is_absolute_or_relative_path(char *cmd)
{
	return (cmd[0] == '/' || (cmd[0] == '.' && (cmd[1] == '/'
				|| (cmd[1] == '.' && cmd[2] == '/'))));
}

void	exec_command(t_command *cmd, t_gen *gen)
{
	char	**t_env;

	if (cmd->args[0] == NULL)
		display_exit(2, "syntax error near unexpected token '|'\n", gen);
	t_env = list_to_tab(gen, gen->env);
	if (t_env == NULL)
		display_exit(1, "list_to_tab failed", gen);
	if (is_absolute_or_relative_path(cmd->args[0]))
		exec_absolute_or_relative_path(cmd, t_env, gen);
	else
		exec_from_path(cmd, t_env, gen);
	free(t_env);
	ft_exit(gen);
}
