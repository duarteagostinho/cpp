/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:37:33 by duandrad          #+#    #+#             */
/*   Updated: 2026/03/25 14:19:22 by duandrad         ###   ########.fr       */
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
		HumanA(std::string _name, Weapon &_weapon);
		~HumanA();
		void	attack();
};

#endif
