/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:22:50 by mguy              #+#    #+#             */
/*   Updated: 2024/07/28 16:06:57 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	fill_tab(int list_size, t_env *copy, t_gen *gen, char **tab)
{
	int		i;
	char	*temp;

	i = -1;
	while (++i < list_size && copy != NULL)
	{
		temp = ft_strjoin(copy->key, "=");
		if (temp == NULL)
			ft_exit(gen);
		tab[i] = ft_strjoin(temp, copy->value);
		free(temp);
		if (tab[i] == NULL)
			ft_exit(gen);
		tab[i][ft_strlen(copy->key) + ft_strlen(copy->value) + 1] = '\0';
		copy = copy->next;
	}
	return (0);
}

char	**list_to_tab(t_gen *gen, t_env *list)
{
	int		list_size;
	t_env	*copy;
	char	**tab;

	list_size = 0;
	copy = list;
	while (copy != NULL && copy != NULL)
	{
		copy = copy->next;
		++list_size;
	}
	copy = list;
	tab = (char **)malloc((list_size + 1) * sizeof(char *));
	if (tab == NULL)
		ft_exit(gen);
	if (fill_tab(list_size, copy, gen, tab) == -1)
		return (free(tab), NULL);
	tab[list_size] = NULL;
	return (tab);
}
