/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:56:18 by duandrad          #+#    #+#             */
/*   Updated: 2025/12/22 18:35:39 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int					value;
		static const int	fract_bits = 8;

	public:
		Fixed() {
			std::cout << "Default constructor called" << std::endl;
			this->value = 0;
		}
		Fixed(const Fixed& obj) {
			std::cout << "Copy constructor called" << std::endl;
			this->value = obj.value;
		}
		Fixed &operator=(const Fixed &obj) {
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &obj)
				this->value = obj.value;
			return *this;
		}
		Fixed 
		~Fixed() {
			std::cout << "Destructor called" << std::endl;
		}
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif
