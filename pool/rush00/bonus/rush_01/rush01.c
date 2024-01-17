/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:58:50 by mguy              #+#    #+#             */
/*   Updated: 2023/08/12 14:58:53 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line(int a, int x)
{
	if (a == 1)
		ft_putchar('/');
	else if (a == x)
		ft_putchar('\\');
	else
		ft_putchar('*');
}

void	last_line(int a, int x)
{
	if (a == 1)
		ft_putchar('\\');
	else if (a == x)
		ft_putchar('/');
	else
		ft_putchar('*');
}

void	other_lines(int a, int x)
{
	if (a == 1 || a == x)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	a;
	int	b;

	a = 1;
	b = 1;
	while (b <= y)
	{
		while (a <= x)
		{
			if (b == 1)
				first_line(a, x);
			else if (b == y)
				last_line(a, x);
			else
				other_lines(a, x);
			a++;
		}
		ft_putchar('\n');
		a = 1;
		b++;
	}
}
