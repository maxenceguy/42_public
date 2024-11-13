/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:11:12 by mguy              #+#    #+#             */
/*   Updated: 2024/05/31 16:12:09 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static bool	is_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (true);
		delim++;
	}
	return (false);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saved_str;
	char		*token;

	if (str == NULL)
		str = saved_str;
	while (*str && is_delim(*str, delim))
		str++;
	if (*str == '\0')
	{
		saved_str = str;
		return (NULL);
	}
	token = str;
	while (*str && !is_delim(*str, delim))
		str++;
	if (*str)
	{
		*str = '\0';
		saved_str = str + 1;
	}
	else
		saved_str = str;
	return (token);
}
