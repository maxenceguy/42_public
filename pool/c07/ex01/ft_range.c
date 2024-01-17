/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:28:48 by mguy              #+#    #+#             */
/*   Updated: 2023/08/20 15:59:50 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	value;

	tab = NULL;
	i = 0;
	value = min;
	if (min >= max)
		return (tab);
	tab = malloc(sizeof(int) * (max - min)); 
	while (value < max)
	{
		tab[i] = value;
		i++;
		value++;
	}
	return (tab);
}

/*
#include <stdio.h>
int	main(void)
{
	int	*tab;
	int	i;

	i = 0;
	tab = ft_range(4, 7);
	if (tab == NULL)
	{
		printf("NULL\n");
		return (0);
	}
	while (tab[i])
	{
		printf("%i, ", tab[i]);
		i++;
	}
	return (0);
}
*/