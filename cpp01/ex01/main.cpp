/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:00:43 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/25 10:42:59 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	
	Zombie *horde = zombieHorde(6, "john");	
	for (int i = 0; i < 6; i++) {
	horde[i].announce();
	}
	delete[] horde;
} 
