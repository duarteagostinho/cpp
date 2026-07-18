#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <limits>
#include <stdexcept>

Span::Span() : _max(0) {}

Span::Span(unsigned int N) : _max(N) {}

Span::Span(const Span &src) : _max(src._max), _span(src._span) {}

Span::~Span() {}

Span &Span::operator=(const Span &src) {
	if (this != &src) {
		_max = src._max;
		_span = src._span;
	}
	return *this;
}

void	Span::addNumber(int n) {
	if (_span.size() < _max)
		_span.push_back(n);
	else
		throw std::out_of_range("Can't add number. Vector is full!");
}

int		Span::elementAt(unsigned int n) {
	return _span[n];
}

unsigned int	Span::shortestSpan() {

	if (_span.size() < 2)
		throw std::exception();

	std::sort(_span.begin(), _span.end());
	int minDiff = std::numeric_limits<int>::max();
	int shortest = 0;
	for (size_t i = 0; i < _span.size() - 1; i++) {
		shortest = (_span[i + 1] - _span[i]); 
		if (shortest < minDiff)
			minDiff = shortest;
	}
	return minDiff;
}

unsigned int	Span::longestSpan() {
	if (_span.size() < 2)
		throw std::exception();
	std::sort(_span.begin(), _span.end());
	return _span.back() - _span.front();
}

