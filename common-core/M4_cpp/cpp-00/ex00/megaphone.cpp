/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:17:54 by mguy              #+#    #+#             */
/*   Updated: 2024/10/12 13:53:53 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

std::string	toUpperCase(const std::string &str) {
	std::string	newString = str;
	for (std::string::size_type i = 0; i < str.length(); i++) {
		newString[i] = std::toupper(newString[i]);
	}
	return (newString);
}

int	main(int ac, char **av) {
	
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; av[i]; i++) {
			std::cout << toUpperCase(av[i]);
		}
		std::cout << std::endl;
	}
	return (0);
}
