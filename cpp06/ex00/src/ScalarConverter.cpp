#include "../inc/ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

ScalarConverter::ScalarConverter() {
    // std::cout << "Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    // std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter() {
    // std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    if (this != &src) {
        // Copy attributes here
    }
    return *this;
}

void	ScalarConverter::convert(std::string const string) {
	if (string.empty()) {
		std::cerr << "Error: Empty string\n";
		return ;
	}
	else if (string.compare("nan") == 0 || string.compare("nanf") == 0) {
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
		return;
	}
	else if (string.compare("+inf") == 0 || string.compare("+inff") == 0) {
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
		return;
	}
	else if (string.compare("-inf") == 0 || string.compare("-inff") == 0) {
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
		return;
	}
	double d = std::strtod(string.c_str(), nullptr);
	if (!(d < 32 || d > 126)) {
		char c = static_cast<char>(d);
		std::cout << "char: " << c << std::endl; 
	}
	if (d >= 0 && d <= 255)
		std::cerr << "char: Non displayable\n";
	else
		std::cerr << "char: Invalid value\n";
	int	i = static_cast<int>(d);
	std::cout << "int: " << i << std::endl;
	float f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n"
	<< "double: " << d << "\n";
}
/*
** --------------------------------- METHODS ----------------------------------
*/

// Add methods here...
