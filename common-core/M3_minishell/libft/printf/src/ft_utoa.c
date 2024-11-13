/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:41:10 by mguy              #+#    #+#             */
/*   Updated: 2023/11/29 19:01:23 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	find_len(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int num)
{
	char			*str;
	size_t			len;
	size_t			i;
	unsigned int	n;

	n = num;
	len = find_len(num);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = len - 1;
	while (n > 9)
	{
		str[i] = (char)(n % 10 + 48);
		i--;
		n = n / 10;
	}
	str[i] = (char)(n + 48);
	str[len] = '\0';
	return (str);
}
