/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:15:42 by mguy              #+#    #+#             */
/*   Updated: 2024/10/28 13:16:44 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <iomanip>
#include <string>

class   Harl {
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
    
    public:
        Harl();
        ~Harl();
        void    complain(std::string level);
};

#endif
