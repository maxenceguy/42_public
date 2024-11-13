/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:30:14 by mguy              #+#    #+#             */
/*   Updated: 2024/10/12 16:37:13 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:29:01 by mguy              #+#    #+#             */
/*   Updated: 2024/10/12 15:11:18 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phone;
        std::string _secret;

    public:
        Contact();
        Contact(const Contact &other);
        ~Contact();
        Contact &operator=(const Contact &other);

		void	setFirstName(const std::string input);
		void 	setLastName(const std::string input);
		void	setNickName(const std::string input);
		void	setPhone(const std::string input);
		void	setSecret(const std::string input);

		std::string	getFirstName() const;
		std::string getLastName() const;
		std::string	getNickName() const;
		std::string	getPhone() const;
		std::string	getSecret() const;
};

#endif
