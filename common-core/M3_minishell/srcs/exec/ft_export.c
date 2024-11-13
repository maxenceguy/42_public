/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:25:55 by mguy              #+#    #+#             */
/*   Updated: 2024/07/31 17:23:16 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	alloc_string(char **s, unsigned long type, int size)
{
	*s = malloc(type * size);
	if (*s == NULL)
		return (-1);
	return (0);
}

char	*fill_part(int i, char **str, char *part, char del)
{
	i = 0;
	while (**str != del)
	{
		part[i] = **str;
		(*str)++;
		i++;
	}
	part[i] = '\0';
	return (part);
}

int	exec_export(t_gen *gen, char **tab)
{
	t_export	exp;

	exp.i = 0;
	while (tab++ && *tab)
	{
		exp.str = *tab;
		while (exp.str[exp.i] && exp.str[exp.i] != '=')
			exp.i++;
		if (exp.str[exp.i])
		{
			if (alloc_string(&exp.key, sizeof(char), exp.i + 1) == -1)
				return (-1);
			exp.key = fill_part(exp.i, &exp.str, exp.key, '=');
			exp.str++;
			if (alloc_string(&exp.value, sizeof(char),
					ft_strlen(exp.str) + 1) == -1)
				return (free(exp.key), -1);
			exp.value = fill_part(exp.i, &exp.str, exp.value, '\0');
			if (ft_export(gen, exp.key, exp.value) == -1)
				return (free(exp.key), free(exp.value), -1);
			free(exp.key);
			free(exp.value);
		}
	}
	return (0);
}

int	new_env_value(t_gen *gen, t_env *env, char *key, char *value)
{
	t_env	*new;

	while (env->next != NULL)
		env = env->next;
	new = malloc(sizeof(t_env));
	if (new == NULL)
		display_exit(1, "malloc error", gen);
	new->key = ft_strdup(key);
	if (new->key == NULL)
	{
		free(new);
		display_exit(1, "malloc error", gen);
	}
	new->value = ft_strdup(value);
	if (new->value == NULL)
	{
		free(new->key);
		free(new);
		display_exit(1, "malloc error", gen);
	}
	env->next = new;
	env->next->next = NULL;
	return (0);
}

// return 0 if success, -1 if malloc error, error_code = 0 or 1 if error
int	ft_export(t_gen *gen, char *key, char *value)
{
	t_env	*env;

	env = gen->env;
	while (env != NULL)
	{
		if (ft_strncmp(key, env->key, ft_strlen(key)) == 0)
		{
			free(env->value);
			if (value)
			{
				env->value = ft_strdup(value);
				if (env->value == NULL)
					return (-1);
			}
			return (0);
		}
		env = env->next;
	}
	env = gen->env;
	if (new_env_value(gen, env, key, value) == -1)
		return (-1);
	gen->error_code = 0;
	return (0);
}
