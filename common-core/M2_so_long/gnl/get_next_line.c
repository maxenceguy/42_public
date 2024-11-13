/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxc <mxc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:45:42 by mguy              #+#    #+#             */
/*   Updated: 2024/02/14 14:55:10 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

int	trim_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] && line[i] == '\n')
	{
		i++;
		while (line[i])
		{
			line[i] = '\0';
			i++;
		}
	}
	return (0);
}

int	get_buffer(char *line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (0);
	i++;
	while (line[i + j])
	{
		buffer[j] = line[i + j];
		j++;
	}
	buffer[j] = '\0';
	return (trim_line(line));
}

char	*read_line(int fd, char *line, char *buffer)
{
	int	n;

	n = 1;
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (n > 0)
	{
		line = gnlstrjoin(line, buffer);
		if (!line)
			return (NULL);
		gnlbzero(buffer, BUFFER_SIZE + 1);
		if (is_line(line))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (gnlbzero(buffer, BUFFER_SIZE + 1), NULL);
		buffer[n] = '\0';
	}
	get_buffer(line, buffer);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[0])
			gnlbzero(buffer, BUFFER_SIZE + 1);
		return (NULL);
	}
	line = read_line(fd, line, buffer);
	if (line == NULL)
		return (free(line), NULL);
	if (!line && buffer[0] == '\0')
		return (NULL);
	return (line);
}
