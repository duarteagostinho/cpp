/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:32:38 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/25 14:23:17 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	
	std::string type;

	public:
		std::string			getType();
		void				setType(std::string type);
	
	Weapon() {
		type = "";
	}
	Weapon(std::string _type) {
		type = _type;
	}
};

#endif