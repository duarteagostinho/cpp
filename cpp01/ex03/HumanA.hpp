/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:37:33 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/25 12:48:09 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	
	Weapon		&weapon;
	std::string	name;
	
	public:
		HumanA(std::string _name, Weapon &_weapon) : weapon(_weapon), name(_name) {}
		void	attack();
		~HumanA() {
			std::cout << "HumanA has been destroyed" << std::endl;
		}
};

#endif
