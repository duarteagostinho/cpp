/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:46:16 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/25 14:36:12 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &_weapon) {
	
	weapon = &_weapon;
}

void	HumanB::attack() {
	
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}