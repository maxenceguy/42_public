/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:46:53 by mguy              #+#    #+#             */
/*   Updated: 2023/08/17 14:26:26 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	while (i < nb)
	{
		ret = ret * (nb - i);
		i++;
	}
	return (ret);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_iterative_factorial(6));
	return (0);
}
*/
