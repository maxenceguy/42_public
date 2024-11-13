/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:27:40 by mguy              #+#    #+#             */
/*   Updated: 2023/11/29 19:00:24 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_hexa(unsigned int n, int i, int len)
{
	if (n < 16)
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a' - i);
		return (1);
	}
	else
	{
		len = print_hexa(n / 16, i, len);
		len += print_hexa(n % 16, i, len);
	}
	return (len);
}

int	ft_hexa(unsigned int n, int i)
{
	int	len;

	len = 0;
	if (n == 0)
		ft_putchar('0');
	else
		return (print_hexa(n, i, len));
	return (1);
}
