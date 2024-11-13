/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:31:53 by mguy              #+#    #+#             */
/*   Updated: 2024/07/25 18:40:12 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Split the path with with ':' as separator
char	**split_path(char *path)
{
	int		count;
	char	*tmp;
	char	*token;
	char	**tab;

	count = 0;
	tmp = ft_strdup(path);
	token = ft_strtok(tmp, ":");
	while (token)
	{
		count++;
		token = ft_strtok(NULL, ":");
	}
	free(tmp);
	tab = malloc((count + 1) * sizeof(char *));
	tmp = ft_strdup(path);
	token = ft_strtok(tmp, ":");
	count = 0;
	while (token)
	{
		tab[count++] = ft_strdup(token);
		token = ft_strtok(NULL, ":");
	}
	tab[count] = NULL;
	return (free(tmp), tab);
}

void	error_code(t_gen *gen, bool value)
{
	if (value)
		gen->error_code = 0;
	else
		gen->error_code = GEN_ERROR;
}
