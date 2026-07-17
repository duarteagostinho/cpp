#include "Span.hpp"
#include <stdexcept>

Span::Span(unsigned int N) : _max(N){}

void	Span::addNumber(int n) {
	if (_span.size() < _max)
		_span.push_back(n);
	else
		throw std::out_of_range("Can't add number. Vector is full!");
}

int		Span::elementAt(unsigned int n) {
	return _span[n];
}
