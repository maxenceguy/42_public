/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:53:37 by mguy              #+#    #+#             */
/*   Updated: 2024/01/17 08:45:19 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	is_in(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && is_in(s1[start], set))
		start++;
	while (end > start && is_in(s1[end], set))
		end--;
	ret = (char *)malloc(sizeof(char) * (end - start + 2));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (end >= start)
	{
		ret[i] = s1[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
