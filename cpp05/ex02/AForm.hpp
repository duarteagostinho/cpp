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
        AForm();
        AForm(const std::string Name, int toSign, int toExecute); // Constructor
        AForm(const AForm &src);   		         // Copy constructor
        ~AForm();                                 // Destructor

        // Operators
        AForm &operator=(const AForm &src); // Copy Assignment

        // Methods
        void	beSigned(Bureaucrat &bc);
        const std::string	getName() const;
		void	set_toSign(const int grade);
		void	set_toExecute(int grade);
		void	set_Name(std::string name);

   	private:
		const std::string	_name;
		bool				_signed;
		const int			_toSign;
		const int			_toExecute;
};

// Stream Operator Overload
std::ostream &operator<<(std::ostream &o, const AForm &i);

#endif
