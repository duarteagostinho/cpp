/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:46 by duandrad          #+#    #+#             */
/*   Updated: 2026/01/15 12:19:56 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* CONTACT CLASS FUNCTIONS */

void	Contact::set_name(std::string name){
	Name = name;
}
void	Contact::set_surname(std::string surname){
	Surname = surname;	
}
void	Contact::set_nick(std::string nick){
	Nickname = nick;
}
void	Contact::set_secret(std::string secret){
	Secret = secret;
}
void	Contact::set_nbr(std::string nbr){
	Number = nbr;
}
std::string	Contact::get_name(){
	return Name;
}
std::string	Contact::get_surname(){
	return Surname;	
}
std::string	Contact::get_nick(){
	return Nickname;
}
std::string	Contact::get_secret(){
	return Secret;
}
std::string	Contact::get_nbr(){
	return Number;
}

/* PHONEBOOK CLASS FUNCTIONS */

void PhoneBook::add(Contact *cont){
	if (currentIndex >= 8)
		currentIndex = 8;
	contacts[currentIndex] = *cont;
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
			if (index >= 0 && index < 9) {
				pb.display(index);
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			else {
				std::cout << "Invalid number, please select an index from 0 to 9" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}
		else if (prompt == "EXIT")
			return 0;
	}
	return 0;
}
