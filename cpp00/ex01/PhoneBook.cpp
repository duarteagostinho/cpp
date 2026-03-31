/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:29 by duandrad          #+#    #+#             */
/*   Updated: 2026/03/25 14:09:24 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PhoneBook::PhoneBook() {
	this->currentIndex = 0;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PhoneBook::~PhoneBook()
{
	std::cout << "Exiting PhoneBook..." << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PhoneBook::add(Contact *cont){
	if (currentIndex >= 8)
		currentIndex = 8;
	contacts[currentIndex % 8] = *cont;
	currentIndex++;
}

void PhoneBook::search() {
	int i = 0;
	while (i < 8)
	{
		if (contacts[i].get_name() != "")
		{
			std::string name = contacts[i].get_name();
			std::string surname = contacts[i].get_surname();
			std::string nickname = contacts[i].get_nick();
			if (name.length() > 10) {
				name.resize(10);
				name[9] = '.';
			}
			if (surname.length() > 10) {
				surname.resize(10);
				surname[9] = '.';
			}
			if (nickname.length() > 10) {
				nickname.resize(10);
				nickname[9] = '.';
			}
			std::cout << std::setw(10) << std::right << i << "|"
					<< std::setw(10) << std::right << name << "|"
					<< std::setw(10) << std::right << surname << "|"
					<< std::setw(10) << std::right << nickname << std::endl;
		}
		i++;
	}
}

void PhoneBook::display(int index) {

	std::string	check;
	check = contacts[index].get_name();
	if (check.empty()) {
		std::cout << "No contact matches the index" << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "Name: " << contacts[index].get_name() << std::endl;
	std::cout << "Surname: " << contacts[index].get_surname() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nick() << std::endl;
	std::cout << "Secret: " << contacts[index].get_secret() << std::endl;
	std::cout << "Number: " << contacts[index].get_nbr() << std::endl << std::endl;
}

std::string	getValidInput(const std::string& fieldName) {

	std::string input;
	while (true)
	{
		std::cout << fieldName << ": ";
		std::getline(std::cin, input);
		if (!std::cin) {
			if (std::cin.eof())
				return "";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}
		if (input.empty())
			std::cout << "Empty field! Please enter ";
		else
			break;
	}
	return input;
}

/* ************************************************************************** */