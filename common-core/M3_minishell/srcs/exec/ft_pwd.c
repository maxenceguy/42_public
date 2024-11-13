/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:29:15 by mguy              #+#    #+#             */
/*   Updated: 2024/07/24 19:17:50 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(t_gen *gen, char **args)
{
	t_env	*env;
	char	cwd[1024];

	(void)args;
	env = gen->env;
	while (env != NULL && ft_strcmp(env->key, "PWD") != 0)
		env = env->next;
	if (env == NULL)
		return (ft_export(gen, "PWD", getcwd(cwd, sizeof(cwd))));
	printf("%s\n", env->value);
	return (0);
}
