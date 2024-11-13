/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:16:47 by mguy              #+#    #+#             */
/*   Updated: 2024/10/26 14:17:20 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

// Create a Zombie, name it, and the zombie announces itself
// Args : a string, zombie name
void	randomChump(std::string name) {
	Zombie	zombie(name);
	zombie.announce();
}
