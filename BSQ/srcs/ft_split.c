/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:46:52 by alermolo          #+#    #+#             */
/*   Updated: 2023/08/30 14:35:12 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		exit (-1);
	while (src[i] && i < n)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_split_size(char *str, char *sep)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_is_sep(str[i], sep)
			&& (ft_is_sep(str[i + 1], sep) || str[i + 1] == '\0'))
			size++;
		i++;
	}
	return (size);
}

void	ft_fill_split(char **split, char *str, char *sep, int split_size)
{
	int	save;
	int	i;
	int	line_no;

	i = 0;
	line_no = 0;
	while (str[i] && ft_is_sep(str[i], sep))
		i++;
	save = i;
	while (str[i] && line_no < split_size)
	{
		if (i != 0 && !ft_is_sep(str[i - 1], sep) && ft_is_sep(str[i], sep))
		{
			split[line_no] = ft_strndup(&str[save], i - save);
			line_no++;
		}
		if (i != 0 && ft_is_sep(str[i - 1], sep) && !ft_is_sep(str[i], sep))
			save = i;
		i++;
	}
	if (i != 0 && str[i] == '\0' && !ft_is_sep(str[i - 1], sep))
		split[line_no] = ft_strndup(&str[save], i);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		split_size;

	split_size = ft_get_split_size(str, charset);
	split = (char **)malloc(sizeof(char *) * (split_size + 1));
	if (!split)
		exit(-1);
	ft_fill_split(split, str, charset, split_size);
	split[split_size] = 0;
	return (split);
}
