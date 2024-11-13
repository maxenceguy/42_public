/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:07:20 by mguy              #+#    #+#             */
/*   Updated: 2024/10/01 21:17:23 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <string>

class	Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce(void) const;
		void	setName(std::string name);
			
	private:
		std::string	_name;
};

// Functionprototype for ZombieHorde
Zombie* zombieHorde(int N, std::string name);

#endif
