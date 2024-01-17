/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:53:01 by mguy              #+#    #+#             */
/*   Updated: 2023/08/31 11:39:52 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (1);
	i = 0;
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	convert(char *nb, char *base)
{
	int	len;
	int	res;
	int	i;
	int	j;

	res = 0;
	len = ft_strlen(base);
	i = 0;
	if (nb[0] == '-')
		i = 1;
	while (nb[i])
	{
		j = 0;
		while (base[j])
		{
			if (nb[i] == base[j])
			{
				res = res * ft_strlen(base) + j;
				i++;
				j = -1;
			}
			j++;
		}
	}
	return (res);
}

int	atoi_base(char *nb, char *base)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	if (check_base(base))
		return (0);
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
		i++;
	while (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			neg *= -1;
		i++;
	}
	return (convert(nb, base) * neg);
}
