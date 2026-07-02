#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
# include <iostream>
# include <string>

class RobotomyRequestForm : public AForm
{
    public:

    	std::string target;
    
        // Constructors & Destructor
        RobotomyRequestForm(std::string Target);                                  // Default
        RobotomyRequestForm(const RobotomyRequestForm &src);            // Copy
        ~RobotomyRequestForm();                                 // Destructor

        // Operators
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src); // Copy Assignment
        void	robotomize() const;
		void	action() const;
    private:
        // Attributes go here
};

// Stream Operator Overload
std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &i);

#endif
