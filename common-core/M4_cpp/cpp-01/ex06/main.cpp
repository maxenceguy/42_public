/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:25:26 by mguy              #+#    #+#             */
/*   Updated: 2024/10/28 13:21:58 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " Enter <log level>\nChoices: DEBUG / INFO / WARNING / ERROR" << std::endl;
        return (1);
    }

    Harl harl;
    harl.complain(av[1]);

    return (0);
}
