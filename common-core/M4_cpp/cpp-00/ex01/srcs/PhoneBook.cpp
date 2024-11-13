/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:35:52 by mguy              #+#    #+#             */
/*   Updated: 2024/10/23 10:28:25 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : _totalContacts(0), _currentContact(0), _maxContacts(8) {}

PhoneBook::PhoneBook(const PhoneBook &other) {
    this->_totalContacts = other._totalContacts;
    this->_currentContact = other._currentContact;
	this->_maxContacts = other._maxContacts;
}

PhoneBook::~PhoneBook() {}

PhoneBook &PhoneBook::operator=(const PhoneBook &other) {
    if (this != &other) {
        this->_totalContacts = other._totalContacts;
        this->_currentContact = other._currentContact;
		this->_maxContacts = other._maxContacts;
    }
    return *(this);
}



// ========== ADD a new Contact ==========

void	PhoneBook::addContact() {
	Contact		newContact = _contacts[_currentContact];
	std::string	input;
	
	std::cout << "Enter FirstName :";
	std::cin >> input;
	if (input == "" || std::cin.eof()) {
		std::cout << "Firstname can't be empty" << std::endl;
		return ;
	}
	newContact.setFirstName(input);

	std::cout << "Enter LastName :";
	std::cin >> input;
	if (input == "" || std::cin.eof()) {
		std::cout << "Lastname can't be empty" << std::endl;
		return ;
	}
	newContact.setLastName(input);

	std::cout << "Enter NickName :";
	std::cin >> input;
	if (input == "" || std::cin.eof()) {
		std::cout << "Nickname can't be empty" << std::endl;
		return ;
	}
	newContact.setNickName(input);

	std::cout << "Enter Phone :";
	std::cin >> input;
	if (input == "" || std::cin.eof()) {
		std::cout << "Phone can't be empty" << std::endl;
		return ;
	}
	newContact.setPhone(input);

	std::cout << "Enter Darkest Secret :";
	std::cin >> input;
	if (input == "" || std::cin.eof()) {
		std::cout << "Darkest secret can't be empty" << std::endl;
		return ;
	}
	newContact.setSecret(input);

	if (_currentContact == _maxContacts)
		_currentContact = 0;
	else {
		if (_totalContacts < _maxContacts)
			_totalContacts++;
	}
	_contacts[_currentContact] = newContact;	
	_currentContact++;
}


// ========== Search New Contact ==========
void	PhoneBook::displayAllContacts(void) const {
	std::cout << std::setw(10) << "Index:" << "|" << std::setw(10) << "Firstname:" << "|" << std::setw(10) << "Lastname:" << "|" << std::setw(10) << "NickName" << std::endl;
	for (int i = 0; i < this->_totalContacts; i++) { 
		std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << this->_contacts[i].getFirstName().substr(0, 9) + ((this->_contacts[i].getFirstName().length() > 9) ? "." : "") << "|"
                  << std::setw(10) << this->_contacts[i].getLastName().substr(0, 9) + ((this->_contacts[i].getLastName().length() > 9) ? "." : "") << "|"
                  << std::setw(10) << this->_contacts[i].getNickName().substr(0, 9) + ((this->_contacts[i].getNickName().length() > 9) ? "." : "") << std::endl;
	}
}

void	PhoneBook::searchContact(void) {
	int	index = -1;

	displayAllContacts();
	std::cout << "\n Enter the index that you want: " << std::endl;
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	if (index == -1 || index > this->_totalContacts - 1) { std::cout << "Invalid index." << std::endl; return ;}
	std::cout << "FirstName: "<< this->_contacts[index].getFirstName() << std::endl;
	std::cout << "LastName: "<< this->_contacts[index].getLastName() << std::endl;
	std::cout << "NickName: "<< this->_contacts[index].getNickName() << std::endl;
	std::cout << "Phone: "<< this->_contacts[index].getPhone() << std::endl;
	std::cout << "Darkest Secret: "<< this->_contacts[index].getSecret() << std::endl;
}
