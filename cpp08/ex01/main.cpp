#include "Span.hpp"

int main() {

	try 
	{
		Span s(3);

		s.addNumber(1);
		std::cout << "s[0] = " << s.elementAt(0) << std::endl;
		s.addNumber(2);
		std::cout << "s[1] = " << s.elementAt(1) << std::endl;
		s.addNumber(3);
		std::cout << "s[2] = " << s.elementAt(2) << std::endl;
		s.addNumber(4);
		std::cout << "s[3] = " << s.elementAt(3) << std::endl;

	}
	catch(std::exception &e)  {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
