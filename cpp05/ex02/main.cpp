#include "inc/PresidentialPardonForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
# include <iostream>

int main()
{
	ShrubberyCreationForm	shrubbery("House");
	RobotomyRequestForm		robotomy("Zezoca");
	PresidentialPardonForm	presidential("Ezekiel");
	shrubbery.createFile();
	robotomy.robotomize();
	presidential.pardon();
}
