/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:45:47 by mguy              #+#    #+#             */
/*   Updated: 2024/10/25 16:00:01 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void) {
	// Use dynamic allocation to persiste without the scope, for larger objects 
	Zombie	*heap = newZombie("Balou");
	if (!heap) {
		std::cerr << "Heap memory allocation failed." << std::endl;
	}
	heap->announce();
	delete heap;
	
	// Use the stack for small / temporary objects with limited scope and lifetime
	randomChump("Mowgli");

	return (0);
}
