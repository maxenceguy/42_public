/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:06:09 by malane            #+#    #+#             */
/*   Updated: 2023/08/13 13:06:15 by malane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_last_line(int a, int x)
{
	if (a == 1)
		ft_putchar('A');
	else if (a == x)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	other_lines(int a, int x)
{
	if (a == 1 || a == x)
		ft_putchar('B');
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
