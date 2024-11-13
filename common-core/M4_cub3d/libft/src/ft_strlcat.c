/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:27:42 by mguy              #+#    #+#             */
/*   Updated: 2024/01/17 08:45:01 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				len;
	int				len_dest;
	unsigned int	i;

	i = 0;
	len = 0;
	len_dest = ft_strlen(dest);
	if (size <= ((unsigned int)ft_strlen(dest)))
		return (ft_strlen(src) + size);
	len = ft_strlen(dest);
	while (src[i] != '\0' && (len + i) < (size - 1))
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (len_dest + ft_strlen(src));
}
