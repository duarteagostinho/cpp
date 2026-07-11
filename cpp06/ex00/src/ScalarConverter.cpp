#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>

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

static	bool	isNanInf(std::string const string) {
	if (string.compare("nan") == 0 || string.compare("nanf") == 0) {
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
		return true;
	}
	else if (string.compare("+inf") == 0 || string.compare("+inff") == 0) {
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
		return true;
	}
	else if (string.compare("-inf") == 0 || string.compare("-inff") == 0) {
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
		return true;
	}
	return false;
}

static bool	isChar(std::string const string) {
	if (string.size() == 1 && !std::isdigit(string[0]) && std::isprint(string[0]))
		return true;
	return false;
}

static bool	isInt(std::string const string) {
	if (string.find(".") != std::string::npos)
		return false;
	for (size_t i = 0; i < string.size(); i++) {
		if (std::isalpha(string[i]))
			return false;
	}
	long num = std::strtol(string.c_str(), nullptr, 10);
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		return false;
	return true;
}

static bool	isFloat(std::string const string) {
	if (string.size() < 3)
		return false;
	if (string[string.size() - 1] != 'f' && string[string.size() - 1] != 'F')
		return false;
	if (string.find(".") == std::string::npos)
		return false;
	char *endptr = NULL;
	std::strtod(string.c_str(), &endptr);
	if (*endptr == 'f' || *endptr == 'F')
		return true;
	return false;
}

static bool	isDouble(std::string const string) {
	if (string.size() < 3)
		return false;
	char *endptr = NULL;
	std::strtod(string.c_str(), &endptr);
	if (*endptr != '\0' || endptr == string.c_str())
		return false;
	return true;
}

static bool	isWhole(double d) {
    return d == static_cast<long>(d);
}

void	ScalarConverter::convert(std::string const string) {
	if (string.empty()) {
		std::cout << "Error: Empty string\n";
		return ;
	}
	if (isNanInf(string) == true)
		return ;
	else if (isChar(string) == true) {
		char c = string[0];
		std::cout << "char: '" << c << "'" << std::endl
		<< "int: " << static_cast<int>(c) << std::endl
		<< "float: " << static_cast<float>(c);
		if (isWhole(c))
			std::cout << ".0";
		std::cout << "f" << std::endl
		<< "double: " << static_cast<double>(c);
		if (isWhole(c))
			std::cout << ".0";
		std::cout << std::endl;
	}
	else if (isInt(string) == true) {
		long l = std::strtol(string.c_str(), nullptr, 10);
		if (l >= 32 && l <= 126)
			std::cout << "char: '" << static_cast<char>(l) << "'" << std::endl;
		else if (l >= 0 && l <= 255)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: "<< static_cast<int>(l)
			<< std::endl << "float: " << static_cast<float>(l);
		if (isWhole(l))
			std::cout << ".0";
		std::cout << "f" << std::endl
			<< "double: " << static_cast<double>(l);
		if (isWhole(l))
			std::cout << ".0";
		std::cout << std::endl;
	}
	else if (isFloat(string) == true) {
		float f = std::strtof(string.c_str(), nullptr);
		if (f >= 32 && f <= 126 && isWhole(f))
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else if (f >= 0 && f <= 255 && isWhole(f))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		if (static_cast<double>(f) >= std::numeric_limits<int>::min() 
				&& static_cast<double>(f) <= std::numeric_limits<int>::max()
				&& isWhole(f))
			std::cout << "int: "<< static_cast<int>(f) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f;
		if (isWhole(f))
			std::cout << ".0";
		std::cout << "f" << std::endl
			<< "double: " << static_cast<double>(f);
		if (isWhole(f))
			std::cout << ".0";
		std::cout << std::endl;
	}
	else if (isDouble(string) == true) {
		double d = std::strtod(string.c_str(), nullptr);
		if (d >= 32 && d <= 126 && isWhole(d))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else if (d >= 0 && d <= 255 && isWhole(d))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		if (d >= std::numeric_limits<int>::min() 
				&& d <= std::numeric_limits<int>::max()
				&& isWhole(d))
			std::cout << "int: "<< static_cast<int>(d) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()) {
			std::cout << "float: " << static_cast<float>(d);
			if (isWhole(d))
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
		else
			std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << d;
		if (isWhole(d))
			std::cout << ".0";
		std::cout << std::endl;
	}
	else
		std::cout << "Unknown type\n";
	return;

}
/*
** --------------------------------- METHODS ----------------------------------
*/

// Add methods here...
