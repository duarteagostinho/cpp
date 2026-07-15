#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include <string>

template <typename T> class Array {

	public:
		Array() {
			_arr = NULL;
			_size = 0;
		}

		Array(unsigned int n) {
			_arr = new T[n]();
			_size = n; 
		}

		Array(const Array &ref) {
			_size =	ref._size;
			if (ref._arr != NULL) {
				_arr = new T[ref._size]();
					for (unsigned int i = 0; i < ref._size; i++)
						_arr[i] = ref._arr[i];
			}
			else
				_arr = NULL;
		}
		~Array() { delete[] _arr; }

		Array &operator=(const Array &src) {
			if (this != &src)
			{
				delete[] _arr;
				_size = src._size;
				if (src._arr != NULL) {
					_arr = new T[_size]();
					for (unsigned int i = 0; i < _size; i++)
						_arr[i] = src._arr[i];
				}
				else
					_arr = NULL;
			}
			return *this;
		}
		T &operator[](unsigned int n) {
			if (n >= _size)
					throw std::exception();
				return _arr[n];
		}

		T const &operator[](unsigned int n) const{
			if (n >= _size)
					throw std::exception();
			return _arr[n];
		}	

		unsigned int size() const{
			return _size;
		}

	private:
		T	 			*_arr;
		unsigned int 	_size;
};

#endif
