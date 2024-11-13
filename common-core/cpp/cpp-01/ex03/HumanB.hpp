/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:08:59 by mguy              #+#    #+#             */
/*   Updated: 2024/10/03 18:02:38 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon  *_weapon;
        std::string _name;

    public:
        HumanB(const std::string& name);
        ~HumanB();

        void setWeapon(Weapon& weapon);
        void attack() const;
};

#endif
