/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:17:41 by mguy              #+#    #+#             */
/*   Updated: 2024/10/26 14:18:18 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

// Create a Zombie, name it, and return it.
// Args : a string, zombie name
Zombie	*newZombie(std::string name) {
	return (new Zombie(name));
}
