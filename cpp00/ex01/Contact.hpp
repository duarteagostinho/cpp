/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:13:10 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/14 12:41:22 by duandrad         ###   ########.fr       */
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
	int					Number;
	
	public:
			Contact() {
						Name = "";
						Surname = "";
						Nickname = "";
						Secret = "";
						Number = 0;
			}
			void		set_name(std::string name);
			void		set_surname(std::string surname);
			void		set_nick(std::string nick);
			void		set_secret(std::string secret);
			void		set_nbr(int nbr);
			std::string	get_name();
			std::string	get_surname();
			std::string	get_nick();
			std::string	get_secret();
			int			get_nbr();
};

#endif //CONTACT_H