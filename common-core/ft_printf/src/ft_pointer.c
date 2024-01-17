/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:27:40 by mguy              #+#    #+#             */
/*   Updated: 2023/11/29 19:00:36 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_pointer(uintptr_t ptr, int len)
{
	if (ptr < 16)
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
		return (1);
	}
	else
	{
		len = print_pointer(ptr / 16, len);
		len += print_pointer(ptr % 16, len);
	}
	return (len);
}

int	ft_pointer(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		return (ft_putstr("(nil)", 0));
	len = 2;
	ft_putchar('0');
	ft_putchar('x');
	if (ptr == 0)
		return (len + ft_putchar('0'));
	else
		return (len + print_pointer(ptr, len));
}
