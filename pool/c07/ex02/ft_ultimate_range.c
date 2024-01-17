/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:53:37 by mguy              #+#    #+#             */
/*   Updated: 2023/08/29 22:18:33 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		range[0][i] = min;
		i++;
		min++;
	}
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	int	ret;
	int	i;
	int	**range;

	i = 0;
	ret = ft_ultimate_range(range, 1, 99);
	if (ret == -1)
	{
		printf("malloc error\n");
		return (0);
	}
	while (i < ret)
	{
		printf("%i - ", range[0][i]);
		i++;
	}
	printf("\n ret = %i\n", ret);
	return (0);
}
*/
