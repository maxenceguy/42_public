/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:52:07 by mguy              #+#    #+#             */
/*   Updated: 2024/02/26 12:41:52 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

void	gnlbzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	s2 = s;
	i = 0;
	while (i < n)
	{
		s2[i] = 0;
		i++;
	}
}

char	*gnlstrjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s = malloc(sizeof(char) * (gnlstrlen(s1) + gnlstrlen(s2) + 1));
	if (s == NULL)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (free(s1), s);
}

size_t	gnlstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != 0)
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
