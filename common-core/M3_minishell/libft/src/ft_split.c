/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:55:35 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:41:23 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1])
				n++;
		}
		if (s[i] != c && i == 0)
			n++;
		i++;
	}
	return (n);
}

char	*add_part(char const *s, char c, size_t i)
{
	size_t	y;
	char	*elt;

	while (s[i] == c)
		i++;
	y = 0;
	while (s[i] && s[i] != c)
	{
		y++;
		i++;
	}
	elt = (char *)malloc(sizeof(char) * (y + 1));
	if (elt == NULL)
		return (NULL);
	i = i - y;
	y = 0;
	while (s[i] && s[i] != c)
	{
		elt[y] = s[i];
		i++;
		y++;
	}
	elt[y] = '\0';
	return (elt);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	n;
	char	**tab;
	size_t	nb_words;

	i = 0;
	n = 0;
	nb_words = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (tab == NULL)
		return (NULL);
	while (n < nb_words)
	{
		while (s[i] == c)
			i++;
		tab[n] = add_part(s, c, i);
		if (tab[n] == NULL)
			return (NULL);
		i += (ft_strlen(tab[n]) + 1);
		n++;
	}
	tab[n] = NULL;
	return (tab);
}

void	ft_split_free(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
