/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:44:15 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/25 14:36:03 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	
	Weapon		*weapon;
	std::string	name;

	public:
		void	attack();
		void	setWeapon(Weapon &_weapon);
	HumanB(std::string _name) {
		name = _name;
		weapon = nullptr;
	}
	~HumanB() {
		std::cout << "HumanB has been destroyed" << std::endl;
	}
};

#endif