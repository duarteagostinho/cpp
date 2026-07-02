# include "inc/Bureaucrat.hpp"
# include "inc/AForm.hpp"
# include "inc/ShrubberyCreationForm.hpp"
# include "inc/RobotomyRequestForm.hpp"
# include "inc/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <exception>
# include <iostream>

int main()
{
	std::srand(time(NULL));
	try
	{
		Bureaucrat	intern("Intern", 150);
		Bureaucrat	manager("Manager", 40);
		Bureaucrat	boss("Boss", 1);

		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robot("Ben");
		PresidentialPardonForm	pardon("Ten");

		std::cout << "\n--- Executing without signed == true ---\n";
		boss.executeForm(shrub);
		std::cout << "\n--- Intern tries to sign ---\n";
		intern.signForm(shrub);
		std::cout << "\n--- Manager signs && executes shrub + robot ---\n";
		manager.signForm(shrub);
		manager.executeForm(shrub);
		manager.signForm(robot);
		manager.executeForm(robot);
		std::cout << "\n--- Manager tries to use PresidentialPardonForm ---\n";
		manager.signForm(pardon);
		manager.executeForm(pardon);
		std::cout << "\n--- Boss signs and executes PresidentialPardonForm ---\n";
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception & e) 
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
