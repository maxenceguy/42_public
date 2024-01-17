/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:57:54 by mguy              #+#    #+#             */
/*   Updated: 2023/08/12 14:57:57 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_last_line(int a, int x)
{
	if (a == 1 || a == x)
		ft_putchar('o');
	else
		ft_putchar('-');
}

void	other_lines(int a, int x)
{
	if (a == 1 || a == x)
		ft_putchar('|');
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
			if (b == 1 || b == y)
				first_last_line(a, x);
			else
				other_lines(a, x);
			a++;
		}
		ft_putchar('\n');
		a = 1;
		b++;
	}
}
