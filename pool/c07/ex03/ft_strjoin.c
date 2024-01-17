/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:31:43 by mguy              #+#    #+#             */
/*   Updated: 2023/08/30 20:14:46 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (dest[len] != '\0')
		len++;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

int	count_all_c(char **strs, int size)
{
	int	n;
	int	i;
	int	y;

	n = 0;
	i = 0;
	y = 0;
	while (y < size)
	{
		while (strs[y][i])
		{
			i++;
			n++;
		}
		y++;
		i = 0;
	}
	return (n);
}

void	cat_strs(char *final, char **strs, char *sep, int size)
{
	int	y;

	y = 0;
	while (y < size)
	{
		final = ft_strcat(final, strs[y]);
		if (y < size - 1)
			final = ft_strcat(final, sep);
		y++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final;
	int		all_c;
	int		len_sep;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	all_c = count_all_c(strs, size);
	len_sep = ft_strlen(sep);
	final = malloc(sizeof(char) * (all_c + ((size - 1) * len_sep) + 1));
	if (final == 0)
		return (NULL);
	cat_strs(final, strs, sep, size);
	return (final);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("str : %s\n", ft_strjoin(argc - 1, argv + 1, "_"));
	return (0);
}
*/
