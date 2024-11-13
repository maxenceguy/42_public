/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:53:32 by mguy              #+#    #+#             */
/*   Updated: 2024/10/26 14:20:56 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

// Allocate N zombies objects in a single allocation 
Zombie* zombieHorde( int N, std::string name ) {
    // Check if it have a less 1 Zombie
    if (N <= 0) {
        std::cout << "At least 1 Zombie is needed." << std::endl;
        return (NULL);
    }
    
    // Allocate memory for N zombie 
    Zombie  *horde = new Zombie[N];
    if (!horde) {
        std::cout << "Memory allocation failed." << std::endl;
        return (NULL);
    }

    // Init each Zombie
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }

    return (horde);
}
