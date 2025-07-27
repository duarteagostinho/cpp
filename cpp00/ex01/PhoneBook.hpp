/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:29 by duandrad          #+#    #+#             */
/*   Updated: 2025/07/27 12:59:10 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
	public:
		std::string	Name;
		std::string	Surname;
		std::string	Nickname;
		std::string	Secret;
		int			Number;
		
		Contact() {
			Name = "";
			Surname = "";
			Nickname = "";
			Secret = "";
			Number = 0;
		}
		Contact(std::string name, std::string surname, std::string nickname,
				std::string secret, int number)
		{
			Name = name;
			Surname = surname;
			Nickname = nickname;
			Secret = secret;
			Number = number;
		}
};

class PhoneBook {
	public:
		Contact contacts[8];
		int currentIndex;
		
	PhoneBook() {
		currentIndex = 0;
	}
	void add(Contact *cont){
		if (currentIndex >= 8)
			currentIndex = 8;
		contacts[currentIndex] = *cont;
		currentIndex++;
	}
	void search(PhoneBook *pb) {
		int i = 0;
		while (i < 8)
		{
			if (pb->contacts[i].Name != "")
			{
				std::string name = pb->contacts[i].Name;
				std::string surname = pb->contacts[i].Surname;
				std::string nickname = pb->contacts[i].Nickname;
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
	void display(PhoneBook *pb, int index) {
		std::cout << std::endl;
		std::cout << "Name: " << pb->contacts[index].Name << std::endl;
		std::cout << "Surname: " << pb->contacts[index].Surname << std::endl;
		std::cout << "Nickname: " << pb->contacts[index].Nickname << std::endl;
		std::cout << "Secret: " << pb->contacts[index].Secret << std::endl;
		std::cout << "Number: " << pb->contacts[index].Number  << std::endl;
	}
};

#endif
