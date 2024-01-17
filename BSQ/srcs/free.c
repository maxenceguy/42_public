/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:03:47 by max               #+#    #+#             */
/*   Updated: 2023/08/29 17:34:42 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	free_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_int_arr(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(t_bsq *bsq)
{
	if (bsq->raw_map != NULL)
		free(bsq->raw_map);
	if (bsq->map != NULL)
		free_char_arr(bsq->map);
	if (bsq->val_map != NULL)
		free_int_arr(bsq->val_map, bsq->size);
	free(bsq);
}
