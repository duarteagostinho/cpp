/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:34:57 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/11 12:11:53 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {

	std::cout << std::endl << "[DEBUG]" << std::endl << 
		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {

	std::cout  << std::endl << "[INFO]" << std::endl << 
		"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {

	std::cout << std::endl << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free." << std::endl << 
		"I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {

	std::cout << std::endl << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string lvl) {

	std::string complainLevel[4] = {"DEBUG", "INFO", "WARNING","ERROR"};
	int i;

	for (i = 0; i < 4; i++){

		if (complainLevel[i] == lvl)
			break ;
	}

	switch (i) {
	
		case(0):
			Harl::debug();
		case(1):
			Harl::info();
		case (2):
			Harl::warning();
		case (3):
			Harl::error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
