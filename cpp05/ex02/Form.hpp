#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
#include <string>
# include "Bureaucrat.hpp"

class AForm {
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
        AForm();                                  // Default
        AForm(const std::string Name, int toSign, int toExecute);
        AForm(const AForm &src);   		         // Copy
        ~AForm();                                 // Destructor

        // Operators
        AForm &operator=(const AForm &src); // Copy Assignment

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
std::ostream &operator<<(std::ostream &o, const AForm &i);

#endif
