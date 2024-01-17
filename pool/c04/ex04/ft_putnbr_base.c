/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:46:54 by mguy              #+#    #+#             */
/*   Updated: 2023/08/21 12:02:45 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (1);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	verif_neg(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (-nbr);
	}
	return (nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		n;
	int		tab[2048];
	char	c;

	n = 0;
	len = 0;
	if (check_error(base))
		return ;
	nbr = verif_neg(nbr);
	while (base[len])
		len++;
	while (nbr)
	{
		tab[n] = nbr % len;
		nbr = nbr / len;
		n++;
	}
	n--;
	while (n >= 0)
	{
		c = base[tab[n]];
		write(1, &c, 1);
		n--;
	}
}

// int	main(void)
// {
// 	ft_putnbr_base(1234, "01");
// 	return (0);
// }
