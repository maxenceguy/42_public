/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:00:32 by mguy              #+#    #+#             */
/*   Updated: 2024/10/03 17:47:21 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon  &_weapon;

    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();

        void    attack() const;
};

#endif
