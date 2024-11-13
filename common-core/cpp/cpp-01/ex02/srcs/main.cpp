/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:45:47 by mguy              #+#    #+#             */
/*   Updated: 2024/10/01 21:44:30 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory address of the string: " << &str << std::endl;
	std::cout << "Memory address of the stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address of the stringREF: " << &stringREF << std::endl;

	std::cout << "Memory address of the string: " << str << std::endl;
	std::cout << "Memory address of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "Memory address of the string: " << stringREF << std::endl;

	return (0);
}
