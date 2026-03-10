/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:56:18 by duandrad          #+#    #+#             */
/*   Updated: 2026/03/03 17:06:05 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int					value;
		static const int	fract_bits = 8;

	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float flow);
		Fixed(const Fixed& obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed();
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		bool	operator>(Fixed &ref);
		bool	operator<(Fixed &ref);
		bool	operator>=(Fixed &ref);
		bool	operator<=(Fixed &ref);
		bool	operator==(Fixed &ref);
		bool	operator!=(Fixed &ref);
		
		Fixed	operator+(Fixed &ref);
		Fixed	operator-(Fixed &ref);
		Fixed	operator*(Fixed &ref);
		Fixed	operator/(Fixed &ref);
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	&operator++(void);
		Fixed	&operator--(void);
};

std::ostream&	operator<<(std::ostream &out, const Fixed &fix);

#endif
