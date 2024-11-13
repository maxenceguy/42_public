/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:18:06 by mguy              #+#    #+#             */
/*   Updated: 2024/10/30 10:17:30 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// ===== Functions ======

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits function called" << std::endl;
    this->_fixedPointValue = raw;
}
