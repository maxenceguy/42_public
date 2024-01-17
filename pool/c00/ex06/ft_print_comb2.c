/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:13:59 by mguy              #+#    #+#             */
/*   Updated: 2023/08/09 15:45:41 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	compare(int m, int c, int d, int u)
{
	if (m > 57 || c > 57 || d > 57 || u > 57)
		return ;
	if (m < 48 || c < 48 || d < 48 || u < 48)
		return ;
	if (m == '9' && c == '8' && d == '9' && u == '9')
	{
		ft_putchar(m);
		ft_putchar(c);
		ft_putchar(' ');
		ft_putchar(d);
		ft_putchar(u);
	}
	else if (m <= d && c < u)
	{
		ft_putchar(m);
		ft_putchar(c);
		ft_putchar(' ');
		ft_putchar(d);
		ft_putchar(u);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ten_unit(int m, int c, int d, int u)
{
	while (d < 58)
	{
		while (u < 58)
		{
			compare(m, c, d, u);
			u++;
		}
		u = 0;
		d++;
	}
}

void	ft_print_comb2(void)
{
	int	m;
	int	c;
	int	d;
	int	u;

	m = 48;
	c = 48;
	d = 48;
	u = 48;
	while (m < 58)
	{
		while (c < 58)
		{
			ten_unit(m, c, d, u);
			d = 0;
			c++;
		}
		c = 0;
		m++;
	}
}
