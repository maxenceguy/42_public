/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:22:00 by mguy              #+#    #+#             */
/*   Updated: 2023/08/11 14:07:53 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	total;
	int	i;

	total = ft_strlen(src);
	i = 0;
	while ((unsigned)i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (total);
}

/*#include <stdio.h>
int	main(void)
{
	char	dest[] = "Hello";
	char	src[] = "I replace dest";
	int	ret;

	ret = ft_strlcpy(dest, src, 5);
	printf("dest :%s,  ret:%i\n", dest, ret);
	return (0);
}*/
