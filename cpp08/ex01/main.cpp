#include "Span.hpp"
#include <vector>

int main() {

	try 
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)  {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try 
	{
		std::vector<int> vec;
		for (int i = 0; i < 10000; i++)
			vec.push_back(i * 2);
		Span sp = Span(10000);
		sp.addMultiple(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		return 0;
	}
	catch(std::exception &e)  {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

}

