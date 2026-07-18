#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>


class Span {
	
	private:
		unsigned int		_max;
		std::vector<int>	_span;	

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &src);

	// Methods
	void			addNumber(int n);
	template<typename Iterator>
	void			addMultiple(Iterator begin, Iterator end) {
		while (begin != end) {
			addNumber(*begin);
			++begin;
		}
	}
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	int				elementAt(unsigned int n);
 };
 
template<typename T>
void	Print(T type) {
	std::cout << type << std::endl;
}

#endif // !SPAN_HPP
