#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
#include <string>
# include "Bureaucrat.hpp"

class Form {
    public:

    class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
   
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
   
	};
    
        // Constructors & Destructor
        Form();                                  // Default
        Form(const std::string Name, int toSign, int toExecute);
        Form(const Form &src);   		         // Copy
        ~Form();                                 // Destructor

        // Operators
        Form &operator=(const Form &src); // Copy Assignment

        // Methods
        void	beSigned(Bureaucrat &bc);
        const std::string	getName() const;

   	private:
		const std::string	_name;
		bool				_signed;
		const int			_toSign;
		const int			_toExecute;
};

// Stream Operator Overload
std::ostream &operator<<(std::ostream &o, const Form &i);

#endif
