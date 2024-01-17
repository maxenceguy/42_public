/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:41:52 by mguy              #+#    #+#             */
/*   Updated: 2023/08/15 17:54:42 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	compare(char *s1, char *s2, int i, int j)
{
	while (s2[j])
	{
		if (s1[i] != s2[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!to_find[0])
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (!str[1] || compare(str, to_find, i, j))
				return (str + i);
		}
		i++;
	}
	return (NULL);
}
