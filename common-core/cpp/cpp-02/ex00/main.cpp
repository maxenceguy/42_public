/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:47:18 by mguy              #+#    #+#             */
/*   Updated: 2024/10/30 10:17:39 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#include <iostream>
#include "Fixed.hpp"

int main() {
    // Test default constructor and getRawBits
	std::cout << "[Test default constructor and getRawBits]" << std::endl;
    Fixed a;
    std::cout << "a (default): " << a.getRawBits() << std::endl;

    // Test copy constructor
	std::cout << "\n[Test copy constructor]" << std::endl;
    Fixed b(a);
    std::cout << "b (copy of a): " << b.getRawBits() << std::endl;

    // Test assignment operator
	std::cout << "\n[Test assignment operator]" << std::endl;
    Fixed c;
    c = b;
    std::cout << "c (assigned from b): " << c.getRawBits() << std::endl;

    // Test setRawBits
	std::cout << "\n[Test setRawBits]" << std::endl;
    a.setRawBits(1234);
    std::cout << "a after setRawBits(1234): " << a.getRawBits() << std::endl;

    // Verify that b and c are unchanged
	std::cout << "\n[Verify that b and c are unchanged]" << std::endl;
    std::cout << "b (should be unchanged): " << b.getRawBits() << std::endl;
    std::cout << "c (should be unchanged): " << c.getRawBits() << std::endl;

    // Additional test cases
	std::cout << "\n[Additional test cases]" << std::endl;
    Fixed d;
    d.setRawBits(5678);
    std::cout << "d after setRawBits(5678): " << d.getRawBits() << std::endl;

	// Testing copy constructor with modified object
	std::cout << "\n[Testing copy constructor with modified object]" << std::endl;
    Fixed e(d);
    std::cout << "e (copy of d): " << e.getRawBits() << std::endl;

	// Testing assignment operator with modified object
	std::cout << "\n[Testing assignment operator with modified object]" << std::endl;
    Fixed f;
    f = a;
    std::cout << "f (assigned from modified a): " << f.getRawBits() << std::endl;

    return 0;
}
