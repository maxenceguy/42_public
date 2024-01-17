/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:40:14 by mguy              #+#    #+#             */
/*   Updated: 2023/08/09 14:14:51 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	compare(int c, int d, int u)
{
	if (c == '7' && d == '8' && u == '9')
	{
		ft_putchar(c);
		ft_putchar(d);
		ft_putchar(u);
	}
	else if (c < d && d < u)
	{
		ft_putchar(c);
		ft_putchar(d);
		ft_putchar(u);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	c;
	int	d;
	int	u;

	c = 48;
	d = 48;
	u = 48;
	while (c < 58)
	{
		while (d < 58)
		{
			while (u < 58)
			{
				compare(c, d, u);
				u++;
			}
			u = 0;
			d++;
		}
		d = 0;
		c++;
	}
}
