/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:21:29 by duandrad          #+#    #+#             */
/*   Updated: 2026/02/11 16:26:48 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook {
	Contact contacts[8];
	int 	currentIndex;
	public:
		PhoneBook();
		~PhoneBook();
		void add(Contact *cont);
		void search();
		void display(int index);
};
std::string	getValidInput(const std::string& fieldName);

#endif