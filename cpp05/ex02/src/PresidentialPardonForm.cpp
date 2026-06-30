# include "../inc/PresidentialPardonForm.hpp"
# include "../inc/AForm.hpp"
/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(std::string Target) : AForm("PresidentialPardonForm", 25, 5), target(Target)
{
    // std::cout << "Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) {
    // std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {
    // std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    if (this != &src) {
        // Copy attributes here
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &i) {
    (void)i;
    o << "Type: PresidentialPardonForm";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::pardon()
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}

// Add methods here...
