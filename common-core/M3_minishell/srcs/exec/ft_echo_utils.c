/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:18:36 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:40:40 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	check_other_chars(char *cmd, int *j, int *start_idx, int *n_flag)
{
	*j = 1;
	if (cmd[*j])
		*start_idx += 1;
	while (cmd[*j])
	{
		*n_flag = 1;
		if (cmd[*j] != 'n')
		{
			*start_idx -= 1;
			*n_flag = 0;
			return ;
		}
		*j += 1;
	}
}

int	check_n(char **cmd, int *start_index, int *n_flag)
{
	int	i;
	int	j;

	i = 1;
	*start_index = 1;
	while (cmd[i] != NULL)
	{
		if (cmd[i][0] == '-')
		{
			check_other_chars(cmd[i], &j, &(*start_index), &(*n_flag));
		}
		else
			break ;
		i++;
	}
	return (0);
}
