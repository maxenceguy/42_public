/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:11:22 by mguy              #+#    #+#             */
/*   Updated: 2024/10/26 15:39:04 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : _weapon(NULL), _name(name) {}

HumanB::~HumanB() {}

// set Weapon pointer to the weapon variable of the class HumanB
void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

// Print attack message if a waepon is define in the class 
void HumanB::attack() const {
    if (this->_weapon) {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    } else {
        std::cout << this->_name << " has no weapon to attack with!" << std::endl;
    }
}
