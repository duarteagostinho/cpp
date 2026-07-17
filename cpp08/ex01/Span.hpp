#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>


class Span {
	
	private:
		unsigned int		_max;
		std::vector<int>	_span;	

	public:
		Span(unsigned int N);

	// Methods
	void			addNumber(int n);
	template<typename Iterator>
	void			addMultiple(Iterator begin, Iterator end);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	int				elementAt(unsigned int n);
 };
 
#endif // !SPAN_HPP
