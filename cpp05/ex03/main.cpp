# include "inc/Bureaucrat.hpp"
# include "inc/AForm.hpp"
# include "inc/Intern.hpp"
# include <iostream>

int main()
{
	std::srand(time(NULL));
	try
	{
		Intern		intern;
		// Bureaucrat	bureaucrat("Bureaucrat", 150);
		// Bureaucrat	manager("Manager", 40);
		// Bureaucrat	boss("Boss", 1);
		//
		// ShrubberyCreationForm	shrub("home");
		// RobotomyRequestForm		robot("Ben");
		// PresidentialPardonForm	pardon("Ten");
		//
		// std::cout << "\n--- Executing without signed == true ---\n";
		// boss.executeForm(shrub);
		// std::cout << "\n--- Intern tries to sign ---\n";
		// bureaucrat.signForm(shrub);
		// std::cout << "\n--- Manager signs && executes shrub + robot ---\n";
		// manager.signForm(shrub);
		// manager.executeForm(shrub);
		// manager.signForm(robot);
		// manager.executeForm(robot);
		// std::cout << "\n--- Manager tries to use PresidentialPardonForm ---\n";
		// manager.signForm(pardon);
		// manager.executeForm(pardon);
		// std::cout << "\n--- Boss signs and executes PresidentialPardonForm ---\n";
		// boss.signForm(pardon);
		// boss.executeForm(pardon);

		// Correct usage
		
		AForm *aF = intern.makeForm("robotomy request", "Chavalo");
		aF->action();
		delete  aF;
		aF = intern.makeForm("presidential pardon", "Linus");
		aF->action();
		delete aF;
		aF = intern.makeForm("shrubbery creation", "Home");
		aF->action();
		delete aF;

		// Incorrect usage

		aF = intern.makeForm("robotomy", "Chavalo");
		if (aF)
			aF->action();
		delete  aF;
		aF = intern.makeForm("Presidential Form", "Linus");
		if (aF)
			aF->action();
		delete aF;
		aF = intern.makeForm("shrubbery creation", "");
		if (aF)
			aF->action();
	}

	catch (std::exception & e) 
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
