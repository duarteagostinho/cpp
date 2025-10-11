/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:16:02 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/11 11:57:33 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {

	Harl harl;

	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "Invalid !" << std::endl;
}
