/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:46 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/04 16:59:02 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	getValidInput(const std::string& fieldName) {

	std::string input;

	std::cout << fieldName << ": ";
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Empty field! Please enter " << fieldName << ": ";
		std::getline(std::cin, input);
	}
	return input;
}

int	main(int ac, char **av) {

	PhoneBook pb;
	Contact cont;
	std::string name, surname, nickname, secret, prompt;
	int number;

	(void)av;
	(void)ac;
	std::cout << std::endl << "Choose option:" << std::endl;
	std::cout << "ADD, SEARCH or EXIT" << std::endl;
	while (1)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, prompt)) {
			std::cout << std::endl << "Input error or EOF detected. Exiting..." << std::endl;
			break;
		}
		if (prompt == "ADD")
		{
			std::cout << "Enter contact details:" << std::endl;
			name = getValidInput("Name");
			surname = getValidInput("Surname");
			nickname = getValidInput("Nickname");
			secret = getValidInput("Secret");
			std::cout << "Phone Number: ";
			while (!(std::cin >> number)) {
				std::cout << "Invalid input. Please enter a number: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			std::cin.ignore();
			cont = Contact(name, surname, nickname, secret, number);
			pb.add(&cont);
			std::cout << std::endl << "Contact added" << std::endl;
			prompt = "";
		}
		else if (prompt == "SEARCH")
		{
			pb.search(&pb);
			std::cin >> number;
			if (number >= 0 && number < 9) {
				pb.display(&pb, number);
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
		}
		else if (prompt == "EXIT")
			break ;
	}
	return 0;
}
