/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:45:29 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/25 14:23:35 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType() const{
	return this->type;
}

void Weapon::setType(const std::string _type) {
	type = _type;
}
