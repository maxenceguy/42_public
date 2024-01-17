/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:23:22 by mguy              #+#    #+#             */
/*   Updated: 2023/08/17 23:05:15 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_str_sort(int argc, char **argv)
{
	int		i;
	int		j;
	int		check;
	char	temp[256];

	i = 0;
	while (++i < argc)
	{
		check = 0;
		j = 0 + i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				ft_strcpy(temp, argv[i]);
				ft_strcpy(argv[i], argv[j]);
				ft_strcpy(argv[j], temp);
				check++;
			}
		}
		if (check > 0 && i == argc - 1)
			i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_str_sort(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
