/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:57:37 by mguy              #+#    #+#             */
/*   Updated: 2023/08/13 12:47:37 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_not_alpha_num(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (i == 0 || (is_not_alpha_num(str[i - 1]) == 0))
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char	ret[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	ft_strcapitalize(ret);
	printf("%s\n", ret);
	return (0);
}*/
