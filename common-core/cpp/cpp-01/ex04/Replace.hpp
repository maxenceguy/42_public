/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:59:48 by mguy              #+#    #+#             */
/*   Updated: 2024/10/28 13:00:46 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

class	Replace {
	private:
		std::string	_filename;
		std::string	_outfilename;
		std::string	_s1;
		std::string	_s2;

	public:
		Replace(const std::string filename, const std::string s1, const std::string s2);
		~Replace();
		
		int replace();
		int	openFiles(std::ifstream *inFile, std::ofstream *outFile);
		std::string	replaceLine(std::string line);
};

#endif
