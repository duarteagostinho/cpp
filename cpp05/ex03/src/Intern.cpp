#include "../inc/Intern.hpp"

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

Intern::Intern() {
    // std::cout << "Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
    // std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {
    // std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

Intern &Intern::operator=(const Intern &src) {
    if (this != &src) {
        // Copy attributes here
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const Intern &i) {
    (void)i; // Evita erro de 'unused parameter' até adicionares lógica
    o << "Type: Intern";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm	*Intern::formShrubbery(std::string target)
{
	AForm	*aF = new ShrubberyCreationForm(target);
	return aF;
}

AForm	*Intern::formRobotomy(std::string target)
{

	AForm	*aF = new RobotomyRequestForm(target);
	return aF;
}

AForm	*Intern::formPresidential(std::string target)
{

	AForm	*aF = new PresidentialPardonForm(target);
	return aF;

}

AForm	*Intern::makeForm(std::string name, std::string target)
{	
	static Forms	forms[] = {
		{ "shrubbery creation", &Intern::formShrubbery },
		{ "robotomy request", &Intern::formRobotomy },
		{ "presidential pardon", &Intern::formPresidential}
	};

	for (int i = 0; i < 3; i++) {
		if (name == forms[i].name) {
			std::cout << "Intern creates " << name << '\n';
			return ((this->*forms[i].func)(target));
		}
	}
	std::cout << "Error: unknown type " << name << '\n';
	return 0;
}
