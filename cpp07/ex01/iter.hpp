#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void	Print(T const &value) {	std::cout << value << std::endl;}

template<typename T, size_t N>
size_t	arr_size(T (&arr)[N]) {
	(void)arr;
	return N;
}

template<typename T, typename Func>
void	iter(T *arr, size_t arr_size, Func f) {
	for (size_t i = 0; i < arr_size; i++) {
		f(arr[i]);
	}
	return;
}

#endif // !ITER_HPP
