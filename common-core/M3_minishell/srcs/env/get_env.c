/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:20:48 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:37:19 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_getenv(t_env *env, char *key)
{
	t_env	*envt;

	envt = env;
	while (envt != NULL)
	{
		if (ft_strcmp(envt->key, key) == 0)
			return (envt->value);
		envt = envt->next;
	}
	return (NULL);
}

// Display str "KEY=VALUE\n" into 2 str "KEY" and "VALUE"
int	parse_key_value(char *str, char **key, char **value)
{
	char	*equal_sign;
	size_t	key_len;
	size_t	value_len;

	equal_sign = ft_strchr(str, '=');
	if (equal_sign)
	{
		key_len = equal_sign - str;
		*key = (char *)malloc(key_len + 1);
		if (*key == NULL)
			return (perror("Failed to allocate memory"), -1);
		ft_strlcpy(*key, str, key_len + 1);
		(*key)[key_len] = '\0';
		value_len = strlen(equal_sign + 1);
		*value = (char *)malloc(value_len + 1);
		if (*value == NULL)
			return (perror("Failed to allocate memory"), -1);
		ft_strlcpy(*value, equal_sign + 1, value_len + 1);
		(*value)[value_len] = '\0';
	}
	return (0);
}

// Create a new node env
t_env	*create_env_node(char **arr, int i)
{
	t_env	*new_node;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	if (parse_key_value(arr[i], &key, &value) == -1)
		return (free(key), free(value), perror("Failed to allocate memory")
			, NULL);
	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (free(key), free(value), perror("Failed to allocate memory")
			, NULL);
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	return (free(key), free(value), new_node);
}

// Get the environment. If arr is NULL,
// the function will create his own environment.
void	get_env(t_gen *gen, char **arr)
{
	t_env	*head;
	t_env	*tail;
	t_env	*new_node;
	int		i;

	head = NULL;
	tail = NULL;
	i = -1;
	while (arr && arr[++i] != NULL)
	{
		new_node = create_env_node(arr, i);
		if (new_node == NULL)
			return (perror("Failed to allocate memory"), free_list(head));
		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
	}
	gen->env = head;
}

// Displqy env
void	print_list(t_env *head)
{
	t_env	*current;

	current = head;
	while (current != NULL)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}
