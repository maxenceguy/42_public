/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:12:06 by mguy              #+#    #+#             */
/*   Updated: 2023/08/31 12:05:14 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	atoi_base(char *nb, char *base);
int	ft_strlen(char *str);
int	check_base(char *base);

char	*ft_rev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	if (str[0] == '-' && str[1] == '0')
		str = "0\0";
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

int	find_size(int nb, char *base_to)
{
	int	len;
	int	i;

	len = ft_strlen(base_to);
	i = 0;
	while (nb > len)
	{
		nb = nb / len;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb, char *base_to)
{
	int		len;
	long	nbr;
	char	*str;
	int		i;

	len = ft_strlen(base_to);
	i = 0;
	nbr = nb;
	str = malloc(sizeof(char) * (find_size(nbr, base_to) + (nbr <= 0) + 1));
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		str[0] = base_to[0];
	while (nbr > 0)
	{
		str[i] = base_to[nbr % len];
		nbr = nbr / len;
		i++;
	}
	if (nb < 0)
		str[i] = '-';
	str[i + 1] = '\0';
	str = ft_rev(str);
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (check_base(base_to) || check_base(base_from))
		return (0);
	return (ft_itoa(atoi_base(nbr, base_from), base_to));
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac != 4)
	{
		printf("3 arguments please !\n");
		return (0);
	}
	char *str = ft_convert_base(av[1], av[2], av[3]);
	printf("new nb : %s\n", str);
	return (0);
}
*/