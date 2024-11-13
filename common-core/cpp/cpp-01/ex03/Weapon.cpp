/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:01:23 by mguy              #+#    #+#             */
/*   Updated: 2024/10/26 15:37:18 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string &type) : _type(type) {}

Weapon::~Weapon() {}

// Return Weapon type
const std::string   &Weapon::getType() const {
    return (_type);
}

// Set the new type to the weapon
void Weapon::setType(const std::string &newType)
{
    this->_type = newType;
}
