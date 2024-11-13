/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:35:26 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:08:36 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	case_one(char *tab, t_gen *gen)
{
	t_env	*tmp;

	if (tab && ft_strcmp(tab, gen->env->key) == 0)
	{
		tmp = gen->env->next;
		free(gen->env->key);
		free(gen->env->value);
		free(gen->env);
		gen->env = tmp;
		return (1);
	}
	return (0);
}

void	remove_env_line(t_env *prev, t_env *current)
{
	prev->next = current->next;
	free(current->key);
	free(current->value);
	free(current);
}

int	ft_unset(t_gen *gen, char **tab)
{
	t_env	*env;
	t_env	*prev;
	int		i;

	i = 0;
	while (tab[i])
	{
		env = gen->env;
		if (case_one(tab[i], gen))
			continue ;
		prev = NULL;
		while (env != NULL)
		{
			if (ft_strcmp(tab[i], env->key) == 0)
			{
				if (prev)
					remove_env_line(prev, env);
				break ;
			}
			prev = env;
			env = env->next;
		}
		i++;
	}
	return (0);
}
