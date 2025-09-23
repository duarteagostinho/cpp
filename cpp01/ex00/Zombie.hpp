/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:00:05 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/06 17:20:41 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	std::string name;
	public:
	void		setName(std::string Name);
	std::string getName();
	void		announce();
	~Zombie() {
		std::cout << name << " has been destroyed" << std::endl;
	}
};
Zombie		*newZombie(std::string Name);
void		randomChump(std::string Name);
#endif //ZOMBIE_HPP