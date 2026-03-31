/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:00:05 by duandrad          #+#    #+#             */
/*   Updated: 2026/03/25 14:19:42 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
 
	std::string name;

	public:
		void		setName(std::string Name);
		std::string getName();
		void		announce();
	Zombie();
	~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif //ZOMBIE_HPP
