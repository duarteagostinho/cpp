/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:47:38 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/25 21:23:13 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int ac, char **av) {
	
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;
	std::string		new_line;
	if (ac != 4) {
		
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	infile.open(av[1]);
	if (!infile.is_open()) {
  	  std::cerr << "Error: Could not open input file." << std::endl;
	  return 1;
	}
	std::string outfilename = std::string(av[1]) + ".replace";
	outfile.open(outfilename.c_str());
	if (!outfile.is_open()) {
  	  std::cerr << "Error: Could not open output file." << std::endl;
	  infile.close();
	  return 1;
	}
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty()) {
		std::cerr << "Error: Search string cannot be empty." << std::endl;
		infile.close();
		outfile.close();
		return 1;
	}
	while (std::getline(infile, line)) {
		new_line = line;
		size_t pos = 0;
		while ((pos = new_line.find(s1, pos)) != std::string::npos) {
			new_line = new_line.substr(0, pos) + s2 + new_line.substr(pos + s1.length());
			pos += s2.length();
		}
		outfile << new_line;
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}
