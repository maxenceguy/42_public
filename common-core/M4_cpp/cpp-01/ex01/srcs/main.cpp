/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:45:47 by mguy              #+#    #+#             */
/*   Updated: 2024/10/26 14:15:57 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void) {
	// Some tests for checking if it works
	int	N = 5;

	// create the Zombie Horde
	Zombie	*horde = zombieHorde(N, "Barry");
	if (!horde) {
		std::cout << "Horde pointer is null." << std::endl;
		return (1);
	}
	
	// Announce each Zombies to be ensure it works correctly
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	delete[] horde;

	return (0);
}
