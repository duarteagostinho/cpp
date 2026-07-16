#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>

template<typename T>
typename T::iterator	easyfind(T &container, int occ) {
	return (std::find(std::begin(container), std::end(container), occ));
}




#endif // !EASYFIND_HPP
