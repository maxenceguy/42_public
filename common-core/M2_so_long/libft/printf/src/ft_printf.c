/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:42:10 by mguy              #+#    #+#             */
/*   Updated: 2023/11/29 19:00:47 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	convert_management(va_list args, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *), 0));
	if (c == 'p')
		return (ft_pointer(va_arg(args, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (ft_putstr(ft_itoa(va_arg(args, int)), 1));
	if (c == 'u')
		return (ft_putstr(ft_utoa(va_arg(args, unsigned int)), 1));
	if (c == 'x')
		return (ft_hexa(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_hexa(va_arg(args, unsigned int), 32));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	convert(const char *s, va_list args, int len)
{
	int	tmp;

	while (*s)
	{
		if (*s == '%')
		{
			tmp = 0;
			tmp = convert_management(args, *(++s));
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else
		{
			write(1, &(*s), 1);
			len++;
		}
		s++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (s == NULL)
		return (-1);
	va_start(args, s);
	len = convert(s, args, len);
	va_end(args);
	return (len);
}
