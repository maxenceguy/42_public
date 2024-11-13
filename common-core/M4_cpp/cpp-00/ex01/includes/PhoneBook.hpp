/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:29:01 by mguy              #+#    #+#             */
/*   Updated: 2024/10/23 10:28:57 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>

#include "Contact.hpp"

class	PhoneBook {
	private:
		Contact	_contacts[9];
		int	_totalContacts;
		int	_currentContact;
		int	_maxContacts;

	public:
		PhoneBook();
		PhoneBook(const PhoneBook &other);
		~PhoneBook();
		PhoneBook &operator=(const PhoneBook &other);

		void	addContact();
		void	searchContact();
		void	displayAllContacts() const ;
};

#endif
