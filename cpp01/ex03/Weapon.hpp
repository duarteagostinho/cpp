/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:32:38 by duandrad          #+#    #+#             */
/*   Updated: 2026/02/11 16:40:19 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

	private:
		std::string type;

	public:
		const std::string	&getType() const;
		void				setType(std::string type);
	
	Weapon();
	Weapon(std::string _type);
};

#endif
