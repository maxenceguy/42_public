/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:11:40 by mguy              #+#    #+#             */
/*   Updated: 2024/01/17 08:45:16 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	size = ft_strlen(str);
	while (str[size] >= 0 && str[size] != c)
	{
		if (size == 0 && str[size] != c)
			return (NULL);
		size--;
	}
	while (i < size)
	{
		str++;
		i++;
	}
	return (str);
}
