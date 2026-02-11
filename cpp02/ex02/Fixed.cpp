/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:49:34 by duandrad          #+#    #+#             */
/*   Updated: 2026/02/11 17:06:39 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" <<std::endl;
	this->value = integer << fract_bits;
}

Fixed::Fixed(const float flow) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(flow * (1 << fract_bits));
}

Fixed::Fixed(const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = obj.value;
}

Fixed& Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->value = obj.value;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {

	return ((static_cast<float>(this->value) / (1 << this->fract_bits)));
}

int	Fixed::toInt(void) const {

	return (this->value >> fract_bits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fix) {

	out << fix.toFloat();
	return out;
}
