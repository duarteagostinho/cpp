#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T &left, T &right) {
	T temp = left;
	left = right;
	right = temp;
}

template<typename T>
T&	min(T &left, T &right) {
	if (left < right)
		return left;
	return right;
}

template<typename T>
T&	max(T &left, T &right) {
	if (left > right)
		return left;
	return right;
}
#endif
