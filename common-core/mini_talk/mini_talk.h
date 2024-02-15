/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:20:32 by mguy              #+#    #+#             */
/*   Updated: 2024/02/14 10:44:13 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_received
{
	size_t	rec;
}	t_received;

typedef struct s_state
{
	int		i;
	pid_t	client_pid;
	char	c;
}	t_state;

#endif
