/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:15:16 by mguy              #+#    #+#             */
/*   Updated: 2024/07/23 19:15:18 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Reallocates a tab of strings, tab is char *** is the old tab,
// size int is the new size of the tab.
// Returns 0 if the reallocation was successful, -1 otherwise.
// The old tab is freed.
int	realloc_tab(char ***tab, int size)
{
	char	**new_tab;
	int		i;

	i = 0;
	new_tab = malloc(sizeof(char *) * (size + 1));
	if (!new_tab)
		return (-1);
	while ((*tab) && (*tab)[i] && i < size)
	{
		new_tab[i] = (*tab)[i];
		i++;
	}
	new_tab[i] = NULL;
	while ((*tab) && (*tab)[i] != NULL)
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	(*tab) = new_tab;
	return (0);
}
