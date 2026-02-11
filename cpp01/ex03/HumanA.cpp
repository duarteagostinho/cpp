/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:46:03 by duandrad          #+#    #+#             */
/*   Updated: 2026/02/11 16:37:45 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(std::string _name, Weapon &_weapon) : weapon(_weapon), name(_name) {}

/*
** ------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA() {
	
	std::cout << name << " has been destroyed" << std::endl;
}

/*
** ------------------------------- METHODS -----------------------------------
*/

void	HumanA::attack() {
	
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
