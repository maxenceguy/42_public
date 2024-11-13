/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:17:42 by mguy              #+#    #+#             */
/*   Updated: 2024/02/15 17:54:36 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

t_received	*g_global_state;

//    - Sends a sequence of signals based on the binary representation of
//      the input string.

void	kill_sig(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			i--;
		}
	}
}

//    - A signal handler for `SIGUSR1` and `SIGUSR2`.
//    - Increments the `received` count for `SIGUSR1` and prints the count
//      for `SIGUSR2`.

void	ft_send(int sig)
{
	t_received	*state;

	state = g_global_state;
	if (sig == SIGUSR1)
		state->rec++;
	else
		ft_printf("%i\n", state->rec);
}

//    - Checks command-line arguments.
//    - Initializes a `State` structure (`state`) and sets `g_global_state`
//      to point to it.
//    - Prints a message indicating the start of sending and receiving.
//    - Sets up signal handlers for `SIGUSR1` and `SIGUSR2`.
//    - Calls `kill_sig` to send signals.
//    - Returns 0.

int	main(int ac, char **av)
{
	t_received	state;

	if (ac != 3 || !av[2][0])
		return (1);
	state.rec = 0;
	g_global_state = &state;
	ft_printf("Send: %s\n", av[2]);
	signal(SIGUSR1, ft_send);
	signal(SIGUSR2, ft_send);
	kill_sig(ft_atoi(av[1]), av[2]);
	return (0);
}

// - The client code is intended to send signals with binary data encoded in
// the input string.
