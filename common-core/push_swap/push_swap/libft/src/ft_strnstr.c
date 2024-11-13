/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:11:56 by mguy              #+#    #+#             */
/*   Updated: 2024/01/17 08:45:13 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	compare(char *s1, const char *s2, int i, int j)
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

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t		i;
	int			j;
	char		*str;

	i = 0;
	j = 0;
	str = (char *)s;
	if (!to_find[0])
		return (str);
	while (i < len && str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (i + ft_strlen(to_find) > len)
				return (NULL);
			if (!str[1] || compare(str, to_find, i, j))
				return (str + i);
		}
		i++;
	}
	return (NULL);
}
