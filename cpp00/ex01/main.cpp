/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:10:51 by duandrad          #+#    #+#             */
/*   Updated: 2026/04/01 17:18:40 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(int ac, char **av) {

	PhoneBook	pb;
	Contact		cont;
	std::string	name, surname, nickname, secret, number, prompt;
	int			index;

	(void)av;
	(void)ac;
	std::cout << std::endl << "Choose option:" << std::endl;
	std::cout << "ADD, SEARCH or EXIT" << std::endl;
	while (std::cin)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, prompt)) {
			return 1;
		}
		if (prompt == "ADD")
		{
			std::cout << "Enter contact details:" << std::endl;
			name = getValidInput("Name");
			if (name.empty())
				return 1;
			surname = getValidInput("Surname");
			if (surname.empty())
				return 1;
			nickname = getValidInput("Nickname");
			if (nickname.empty())
				return 1;
			secret = getValidInput("Secret");
			if (secret.empty())
				return 1;
			number = getValidInput("Number");
			if (number.empty())
				return 1;
			cont.set_name(name);
			cont.set_surname(surname);
			cont.set_nick(nickname);
			cont.set_secret(secret);
			cont.set_nbr(number);
			pb.add(&cont);
			std::cout << std::endl << "Contact added" << std::endl;
			prompt = "";
		}
		else if (prompt == "SEARCH")
		{
			pb.search();
			std::cin >> index;
			if (index >= 0 && index < 8) {
				pb.display(index);
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			else {
				std::cout << "Invalid number, please select an index from 0 to 7" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}
		else if (prompt == "EXIT")
			return 0;
	}
	return 0;
}
