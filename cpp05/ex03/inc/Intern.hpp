#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	
	typedef AForm* (Intern::*execFunc)(std::string);

	struct Forms {
		std::string name;
		execFunc	func;
	};

    public:
        // Constructors & Destructor
        Intern();                                  // Default
        Intern(const Intern &src);            // Copy
        ~Intern();                                 // Destructor

        // Operators
        Intern &operator=(const Intern &src); // Copy Assignment
		
		AForm* makeForm(std::string name, std::string target);

	private: 
		AForm	*formShrubbery(std::string target);
		AForm	*formRobotomy(std::string target);
		AForm	*formPresidential(std::string target);

};

// Stream Operator Overload
std::ostream &operator<<(std::ostream &o, const Intern &i);

#endif
