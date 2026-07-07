#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter {
 
    private:
        // Attributes go here
        ScalarConverter();                                  // Default
        ScalarConverter(const ScalarConverter &src);            // Copy
        ~ScalarConverter();      
	public:
        ScalarConverter &operator=(const ScalarConverter &src); // Copy Assignment

		static void	convert(std::string const);
};


#endif
