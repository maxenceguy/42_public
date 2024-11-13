/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:28:12 by mguy              #+#    #+#             */
/*   Updated: 2024/10/23 10:28:06 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int	main(void) {
	PhoneBook dbook;
	PhoneBook book(dbook);
	std::string	command;
	while (1) {
		if (std::cin.eof()) {
			return (std::cout << "End of input (EOF) detected." << std::endl, 1);
		} else if (std::cin.fail()) {
			return (std::cout << "Input error detected." << std::endl, 0);
		}
		std::cout << "ADD, SEARCH or EXIT" << std::endl;
		std::cin >> command;
		if (command == "ADD") { book.addContact(); }
		if (command == "SEARCH") { book.searchContact(); }
		if (command == "EXIT") { std::cout << "Good Bye !" << std::endl; break ; }
	}
	return (0);
}
