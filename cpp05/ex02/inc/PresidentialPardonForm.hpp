#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : AForm
{
    public:
	
		std::string target;
		// Constructors
        PresidentialPardonForm(std::string Target);             
        PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

        // Operators
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		// Methods
		void	pardon();

    private:
        // Attributes go here
};

#endif
