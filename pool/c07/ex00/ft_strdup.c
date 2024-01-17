/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:13:34 by mguy              #+#    #+#             */
/*   Updated: 2023/08/18 13:27:44 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*str;
	char	*str2;

	if (argc == 0)
		return (0);
	str = ft_strdup(argv[1]);
	str2 = strdup(argv[1]);
	printf("str1 : %s\n", str);
	printf("str2 : %s\n", str2);
	free(str);
	free(str2);
	return (0);
}
*/
