/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:16:32 by alermolo          #+#    #+#             */
/*   Updated: 2023/08/30 11:17:02 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*read_stdin(void)
{
	char	buffer[1024];
	int		to_read;
	int		read_size;

	to_read = open("raw_map", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (to_read == -1)
		return (NULL);
	read_size = read(0, buffer, 1024);
	while (read_size >= 1024 || read_size == -1)
	{
		if (read_size == -1)
			return (NULL);
		write(to_read, buffer, 1024);
		read_size = read(0, buffer, 1024);
	}
	write(to_read, buffer, read_size);
	close(to_read);
	return ("raw_map");
}
