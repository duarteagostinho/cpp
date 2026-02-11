/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:44:15 by duandrad          #+#    #+#             */
/*   Updated: 2026/02/11 16:38:35 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	
	Weapon		*weapon;
	std::string	name;

	public:
		HumanB(std::string _name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &_weapon);
};

#endif
