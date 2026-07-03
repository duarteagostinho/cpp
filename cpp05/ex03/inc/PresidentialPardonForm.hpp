#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
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
		void	pardon() const;
		void	action() const;

    private:
        // Attributes go here
};

#endif
