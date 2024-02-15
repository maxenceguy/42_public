/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:49:19 by mguy              #+#    #+#             */
/*   Updated: 2024/02/14 11:26:12 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

t_state	*g_global_state;

// - This function is a signal handler for `SIGUSR1` and `SIGUSR2`.
// - It updates the state based on the received signals, counts bits, 
// and processes character transmission.

void	ft_action(int sig)
{
	static int	bit;
	static char	octet;

	if (sig == SIGUSR2)
		octet += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(octet);
		bit = 0;
		octet = 0;
	}
}

//    - Prints the server's PID using `getpid()`.
//    - Initializes a `struct sigaction` (`s_sigaction`) to handle signals
//      with `ft_action`.
//    - Enters an infinite loop (`while (1)`) using `pause()` to wait
//      for signals.

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		return (0);
	ft_printf("Server PID: [%i]\n", getpid());
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	while (1)
		pause();
	return (0);
}

// - The server code is intended to receive signals, interpret binary data,
// and print the result.
