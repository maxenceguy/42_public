/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:06:16 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 10:51:03 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	recover_path(t_gen *gen)
{
	while (chdir("..") == -1)
	{
		if (strcmp(getcwd(NULL, 0), "/") == 0)
		{
			perror("recover_path: cannot recover path");
			return (gen->error_code = 1, -1);
		}
	}
	return (0);
}

static char	*get_cd_path(t_gen *gen, char *arg_path)
{
	if (arg_path == NULL || ft_strcmp(arg_path, "~") == 0)
		return (ft_getenv(gen->env, "HOME"));
	if (ft_strcmp(arg_path, "-") == 0)
		return (ft_getenv(gen->env, "OLDPWD"));
	return (arg_path);
}

static int	update_env_vars(t_gen *gen, char *oldpwd)
{
	char	newpwd[2056];

	if (ft_export(gen, "OLDPWD", oldpwd) < 0)
		return (gen->error_code = 1, -1);
	if (getcwd(newpwd, sizeof(newpwd)) == NULL)
	{
		perror("getcwd error");
		gen->error_code = 1;
		return (-1);
	}
	if (ft_export(gen, "PWD", newpwd) < 0)
	{
		gen->error_code = 1;
		return (-1);
	}
	return (0);
}

static int	handle_getcwd_error(t_gen *gen, char *oldpwd)
{
	if (recover_path(gen) == -1)
	{
		gen->error_code = 1;
		return (-1);
	}
	if (getcwd(oldpwd, 2056) == NULL)
	{
		perror("getcwd error after recovery");
		gen->error_code = 1;
		return (-1);
	}
	return (0);
}

int	ft_cd(t_gen *gen, char *arg_path)
{
	char	oldpwd[2056];
	char	*path;

	if (getcwd(oldpwd, sizeof(oldpwd)) == NULL)
	{
		if (handle_getcwd_error(gen, oldpwd) == -1)
			return (-1);
	}
	path = get_cd_path(gen, arg_path);
	if (path == NULL)
	{
		printf("cd: No such file or directory\n");
		return (gen->error_code = 1, -1);
	}
	if (chdir(path) == -1)
	{
		perror("chdir");
		return (gen->error_code = 1, -1);
	}
	if (update_env_vars(gen, oldpwd) < 0)
		return (-1);
	gen->error_code = 0;
	return (0);
}
