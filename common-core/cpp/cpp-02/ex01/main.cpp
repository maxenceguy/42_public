/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:47:18 by mguy              #+#    #+#             */
/*   Updated: 2024/10/30 11:04:38 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
    // Default constructor
    Fixed a;

    // Integer constructor
    Fixed const b(10);

    // Float constructor
    Fixed const c(42.42f);

    // Copy constructor
    Fixed const d(b);

    // Assignment operator with a floating-point number
    a = Fixed(1234.4321f);

    // Displaying the fixed-point numbers using the overloaded << operator
    std::cout << "\na is " << a << std::endl;
    // a should be around 1234.43

    std::cout << "b is " << b << std::endl;
    // b should be 10

    std::cout << "c is " << c << std::endl;
    // c should be around 42.4219

    std::cout << "d is " << d << std::endl;
    // d should be 10 (copy of b)

    // Testing toInt function to convert fixed-point numbers to integer
    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;
    // Should output 1234

    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // Should output 10

    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // Should output 42

    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    // Should output 10 (same as b)

    // Testing toFloat function to convert fixed-point numbers to floating-point
    std::cout << "\na is " << a.toFloat() << " as float" << std::endl;
    // Should output around 1234.43

    std::cout << "b is " << b.toFloat() << " as float" << std::endl;
    // Should output 10.0

    std::cout << "c is " << c.toFloat() << " as float" << std::endl;
    // Should output around 42.4219

    std::cout << "d is " << d.toFloat() << " as float\n" << std::endl;
    // Should output 10.0 (same as b)

    return 0;
}
