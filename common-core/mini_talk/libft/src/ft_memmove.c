/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:57:32 by mguy              #+#    #+#             */
/*   Updated: 2024/01/17 08:44:34 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;

	dest2 = dest;
	src2 = src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest <= src || dest >= (src + n))
	{
		while (n--)
			*dest2++ = *src2++;
	}
	else
	{
		dest2 += n;
		src2 += n;
		while (n--)
			*(--dest2) = *(--src2);
	}
	return (dest);
}
