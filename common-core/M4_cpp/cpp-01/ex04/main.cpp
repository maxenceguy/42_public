/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:55:27 by mguy              #+#    #+#             */
/*   Updated: 2024/10/28 13:11:28 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

// # paramters order: filename s1 s2
int	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Arguments : filename s1 s2" << std::endl;
		return (1);
	}
	Replace rep = Replace(av[1], av[2], av[3]);
	
	if (rep.replace())
		return (1);
		
	return (0);	
}
