/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:27:05 by mguy              #+#    #+#             */
/*   Updated: 2024/10/22 15:08:35 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

Contact::Contact() {
    // Initialization of the contact fields
    _firstName = "";
    _lastName = "";
    _nickName = "";
    _phone = "";
    _secret = "";
}

Contact::Contact(const Contact &other) {
    *this = other;
}

Contact::~Contact() {
    // Destructor logic (if needed)
}

Contact &Contact::operator=(const Contact &other) {
    if (this != &other) {
        this->_firstName = other._firstName;
        this->_lastName = other._lastName;
        this->_nickName = other._nickName;
        this->_phone = other._phone;
        this->_secret = other._secret;
    }
    return *this;
}

void	Contact::setFirstName(std::string input) {this->_firstName = input;}
void	Contact::setLastName(std::string input) {this->_lastName = input;}
void	Contact::setNickName(std::string input) {this->_nickName = input;}
void	Contact::setPhone(std::string input) {this->_phone = input;}
void	Contact::setSecret(std::string input) {this->_secret = input;}


std::string	Contact::getFirstName() const {return (this->_firstName);}
std::string	Contact::getLastName() const {return (this->_lastName);}
std::string	Contact::getNickName() const {return (this->_nickName);}
std::string	Contact::getPhone() const {return (this->_phone);}
std::string	Contact::getSecret() const {return (this->_secret);}
