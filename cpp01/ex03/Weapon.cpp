/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:45:29 by duandrad          #+#    #+#             */
/*   Updated: 2026/02/11 16:40:25 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	type = "";
}
Weapon::Weapon(std::string _type) {
	type = _type;
}

const std::string	&Weapon::getType() const{
	return this->type;
}

void Weapon::setType(const std::string _type) {
	type = _type;
}
