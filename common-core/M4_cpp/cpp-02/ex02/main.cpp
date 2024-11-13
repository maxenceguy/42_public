/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:47:18 by mguy              #+#    #+#             */
/*   Updated: 2024/10/30 11:01:42 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    // Testing basic functionality and arithmetic operators
    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << a << std::endl;                 // Should be 0
    std::cout << "b: " << b << std::endl;                 // Should be around 10.1016

    // Testing pre-increment and post-increment operators
    std::cout << "Increment tests:" << std::endl;
    std::cout << "++a: " << ++a << std::endl;             // Pre-increment: a should now be a small positive value
    std::cout << "a after pre-increment: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;             // Post-increment: a's value before incrementing
    std::cout << "a after post-increment: " << a << std::endl;

    // Testing comparison operators
    std::cout << "Comparison tests:" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    // Testing arithmetic operators
    std::cout << "Arithmetic tests:" << std::endl;
    Fixed c = a + b;
    std::cout << "a + b: " << c << std::endl;
    c = a - b;
    std::cout << "a - b: " << c << std::endl;
    c = a * b;
    std::cout << "a * b: " << c << std::endl;
    c = a / b;
    std::cout << "a / b: " << c << std::endl;

    // Testing min and max static functions
    std::cout << "Min/Max tests:" << std::endl;
    std::cout << "Fixed::min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << std::endl;

    // Edge cases: Check min and max with identical values
    Fixed const d(b);
    std::cout << "Fixed::min(b, d) (identical values): " << Fixed::min(b, d) << std::endl;
    std::cout << "Fixed::max(b, d) (identical values): " << Fixed::max(b, d) << std::endl;

    // Testing decrement operators
    std::cout << "Decrement tests:" << std::endl;
    std::cout << "--a: " << --a << std::endl;             // Pre-decrement
    std::cout << "a after pre-decrement: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;             // Post-decrement
    std::cout << "a after post-decrement: " << a << std::endl;

    // Division by zero (may crash the program as acceptable)
    try {
        Fixed zero;
        Fixed result = b / zero;
        std::cout << "Result of division by zero: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception on division by zero: " << e.what() << std::endl;
    }

    return 0;
}
