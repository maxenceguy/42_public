/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:28:06 by mguy              #+#    #+#             */
/*   Updated: 2023/08/17 22:02:48 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ret;

	ret = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		ret = ret * nb;
		power--;
	}
	return (ret);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_iterative_power(4, 5));
	return (0);
}
*/
