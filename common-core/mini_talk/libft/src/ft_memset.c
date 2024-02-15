/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:24:01 by mguy              #+#    #+#             */
/*   Updated: 2024/01/17 08:44:36 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *p, int value, size_t count)
{
	size_t			i;
	unsigned char	*p2;

	p2 = p;
	i = 0;
	while (i < count)
	{
		p2[i] = (unsigned char)value;
		i++;
	}
	return (p2);
}
