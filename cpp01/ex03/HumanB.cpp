/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:46:16 by duandrad          #+#    #+#             */
/*   Updated: 2026/02/11 16:39:09 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name) {
	name = _name;
	weapon = 0;
}

HumanB::~HumanB() {
	std::cout << "HumanB has been destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon &_weapon) {
	
	weapon = &_weapon;
}

void	HumanB::attack() {
	
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}