/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:13:10 by duandrad          #+#    #+#             */
/*   Updated: 2026/01/15 11:31:26 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include "PhoneBook.hpp"
#include <iostream>

class Contact {
	
	std::string			Name;
	std::string			Surname;
	std::string			Nickname;
	std::string			Secret;
	std::string				Number;
	
	public:
			Contact() {
						Name = "";
						Surname = "";
						Nickname = "";
						Secret = "";
						Number = "";
			}
			void		set_name(std::string name);
			void		set_surname(std::string surname);
			void		set_nick(std::string nick);
			void		set_secret(std::string secret);
			void		set_nbr(std::string nbr);
			std::string	get_name();
			std::string	get_surname();
			std::string	get_nick();
			std::string	get_secret();
			std::string	get_nbr();
};

#endif //CONTACT_H