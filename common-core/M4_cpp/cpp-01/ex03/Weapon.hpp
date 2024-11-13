/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:00:32 by mguy              #+#    #+#             */
/*   Updated: 2024/10/03 17:59:02 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <iomanip>
#include <string>

class Weapon
{
    private:
        std::string _type;
    public:
		Weapon();
        Weapon(const std::string &type);
        ~Weapon();

        const std::string &getType() const;
        void  setType(const std::string &newtype);
};

#endif
