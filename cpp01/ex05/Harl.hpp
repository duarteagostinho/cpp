/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 21:30:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/26 16:37:23 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
	
	std::string _level;
	
	public:
		void complain(std::string level);
		void set_level(std::string level);
		std::string get_level();
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

struct Level
{
	{"DEBUG", &Harl::}
};


#endif