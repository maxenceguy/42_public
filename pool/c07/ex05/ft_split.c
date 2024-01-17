/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:01:01 by mguy              #+#    #+#             */
/*   Updated: 2023/08/31 15:02:00 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	nb_str(char *str, char *sep)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (is_in(str[i], sep) && !is_in(str[i], sep) && i > 0 && str[i + 1])
			n++;
		i++;
	}
	return (n);
}

int	add_in_tab(char *str, int i, char *tab_s, char *charset)
{
	int	y;

	y = i;
	while (str[y] && !is_in(str[y], charset))
		y++;
	tab_s = malloc(sizeof(char) * (10 + 1));
	if (tab_s == NULL)
		return (-1);
	y = 0;
	while (str[i] && !is_in(str[i], charset))
	{
		tab_s[y] = str[i];
		i++;
		y++;
	}
	tab_s[y] = '\0';
	return (i);
}

char	**add_str(char *str, char *charset, char **tab)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (is_in(str[i], charset))
			y++;
		while (is_in(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			i = add_in_tab(str, i, tab[y], charset);
			if (i == -1)
				return (NULL);
		}
	}
	tab[y] = NULL;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nb_strs;
	int		y;

	y = 0;
	nb_strs = nb_str(str, charset);
	tab = malloc(sizeof(char *) * (nb_strs + 1));
	if (tab == NULL)
		return (NULL);
	tab[nb_strs] = NULL; 
	if (!charset[0] && str[0])
		tab[y] = str;
	if (!str[0])
		return (tab);
	tab = add_str(str, charset, tab);
	if (tab == NULL)
		return (NULL);
	return (tab);
}
