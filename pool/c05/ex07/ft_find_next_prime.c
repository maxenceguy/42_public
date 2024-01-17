/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:03:08 by mguy              #+#    #+#             */
/*   Updated: 2023/08/22 14:42:32 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2 || nb > 2147483647)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2 || nb > 2147483647)
		return (0);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_find_next_prime(2147483646));
	return (0);
}
*/
