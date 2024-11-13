/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:32:04 by mguy              #+#    #+#             */
/*   Updated: 2023/11/14 20:47:21 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	size = ft_strlen(s) - start + 1;
	if ((int)len >= 0 && (len + 1) < size)
		size = len + 1;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		j;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(sizeof(char) * get_size(s, start, len));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
