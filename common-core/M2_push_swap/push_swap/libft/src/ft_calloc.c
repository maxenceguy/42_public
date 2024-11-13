/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:31:38 by mguy              #+#    #+#             */
/*   Updated: 2024/01/17 08:44:07 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t EltCount, size_t EltSize)
{
	void	*temp;

	temp = malloc(EltCount * EltSize);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, EltCount * EltSize);
	return (temp);
}
