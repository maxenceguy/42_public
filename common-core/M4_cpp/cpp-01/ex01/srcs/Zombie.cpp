/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:15:27 by mguy              #+#    #+#             */
/*   Updated: 2024/10/26 14:16:09 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) :  _name(name) {
	std::cout << "Zombie " << this->_name << " is created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->_name << " is destroyed" << std::endl;
}

void	Zombie::announce() const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	_name = name;
	std::cout << "Zombie " << this->_name << " is initialized" << std::endl;
}
