/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:36:00 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:08:09 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	run_builtin(t_command *current, t_gen *gen)
{
	if (ft_strcmp(current->args[0], "cd") == 0)
		ft_cd(gen, current->args[1]);
	if (ft_strcmp(current->args[0], "echo") == 0)
		ft_echo(current->args, gen);
	if (ft_strcmp(current->args[0], "env") == 0)
		print_list(gen->env);
	if (ft_strcmp(current->args[0], "pwd") == 0)
		ft_pwd(gen, current->args);
	if (ft_strcmp(current->args[0], "export") == 0)
		exec_export(gen, current->args);
	if (ft_strcmp(current->args[0], "unset") == 0)
		ft_unset(gen, current->args);
	if (ft_strcmp(current->args[0], "exit") == 0)
		ft_exit(gen);
}

bool	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (true);
	if (ft_strcmp(cmd, "echo") == 0)
		return (true);
	if (ft_strcmp(cmd, "env") == 0)
		return (true);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (true);
	if (ft_strcmp(cmd, "export") == 0)
		return (true);
	if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	if (ft_strcmp(cmd, "exit") == 0)
		return (true);
	return (false);
}

void	run_builtin2(t_command *current, t_gen *gen)
{
	if (ft_strcmp(current->args[0], "cd") == 0)
		ft_cd(gen, current->args[1]);
	if (ft_strcmp(current->args[0], "export") == 0)
		exec_export(gen, current->args);
	if (ft_strcmp(current->args[0], "unset") == 0)
		ft_unset(gen, current->args);
	if (ft_strcmp(current->args[0], "exit") == 0)
		ft_exit(gen);
}

bool	is_builtin2(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (true);
	if (ft_strcmp(cmd, "export") == 0)
		return (true);
	if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	if (ft_strcmp(cmd, "exit") == 0)
		return (true);
	return (false);
}
