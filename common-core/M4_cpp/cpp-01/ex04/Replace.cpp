/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:08:57 by mguy              #+#    #+#             */
/*   Updated: 2024/10/28 13:11:02 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(const std::string filename, const std::string s1, const std::string s2) : _filename(filename), _outfilename(filename + ".replace"), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

// Open the file and create the .replace 
int	Replace::openFiles(std::ifstream *inFile, std::ofstream *outFile) {
	(*inFile).open(_filename.c_str(), std::ifstream::in);
	(*outFile).open(_outfilename.c_str(), std::ofstream::out);

	// Check the correct opening 
	if (!inFile || !outFile) {
		std::cout << "Error while open files." << std::endl;
		(*inFile).close();
		(*outFile).close();
		return (1);
	}
	return (0);
}

// Replace the occurrence defined in the class of the line 
std::string	Replace::replaceLine(std::string line) {
	std::string	newLine;
	std::string::size_type i = line.find(_s1);

	if (i == std::string::npos)
    	return (line);
	newLine.append(line.begin(), line.begin() + i);
	newLine.append(_s2);
	newLine.append(line.begin() + i + _s1.length(), line.end());
	return (newLine);
}

// Replace all occurence arg2 by arg3 form file arg1
int Replace::replace()
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	
	std::string		line;
	std::string		newLine;

	if (openFiles(&inFile, &outFile)) {
		return (1);
	}

	// take lines one by one and send it in the replaceLine function
	while (std::getline(inFile, line)) {
		newLine = replaceLine(line);
		if (inFile.eof())
			break;
		
		// send edited line in the new file
		outFile << newLine << std::endl;
	}
	
	inFile.close();
	outFile.close();

	return (0);
}
