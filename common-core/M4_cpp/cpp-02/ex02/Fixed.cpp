/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:18:06 by mguy              #+#    #+#             */
/*   Updated: 2024/10/30 11:17:22 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
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


// ===== Functions =====

// Retrun the raw value of the fixed-point value
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called" << std::endl;
	return (this->_fixedPointValue);
}

// Set the raw value of the fixed-point number
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// Convert fixed point of the class in float, and return it
float	Fixed::toFloat(void) const {
	return (static_cast<float>(_fixedPointValue) / ( 1 << _fractionalBits));
}

// Convert fixed point of the class in int, and return it
int	Fixed::toInt(void) const {
	return (_fixedPointValue >> _fractionalBits);
}

// Insert operators
bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointValue >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointValue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointValue != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->_fixedPointValue * other.getRawBits()) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
	if (result.getRawBits() == 0) {
		std::cout << "Can not devide by 0" << std::endl;
		return (Fixed(0));
	}
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other.getRawBits());
    return result;
}

Fixed &Fixed::operator++() {
	this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
