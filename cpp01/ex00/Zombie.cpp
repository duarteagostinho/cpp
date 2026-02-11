/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:48:25 by duandrad          #+#    #+#             */
/*   Updated: 2026/02/11 16:32:25 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie() {}

/*
** ------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie() {
	
	std::cout << name << " has been destroyed" << std::endl;
}

/*
** ------------------------------- METHODS -----------------------------------
*/


void	Zombie::announce() {
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
void	Zombie::setName(std::string Name) {
	name = Name;
}

/*
** ------------------------------- ACCESSORS --------------------------------
*/

std::string	Zombie::getName() {
	return name;
}
