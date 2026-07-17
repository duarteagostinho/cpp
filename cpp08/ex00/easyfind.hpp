#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>

template<typename T>
typename T::iterator	easyfind(T &container, int occ) {
	typename T::iterator it = std::find(container.begin(), container.end(), occ);
	if (it != container.end())
		return it;
	else
		throw std::out_of_range("Element not found");
}

#endif
