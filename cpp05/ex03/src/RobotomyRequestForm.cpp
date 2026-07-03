#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/AForm.hpp"
#include <cstdlib>

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string Target) : AForm("RobotomyRequestForm", 72, 45), target(Target) 
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), target(src.target)
{
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src) {
        // Copy attributes here
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::robotomize() const
{
	std::cout << this->target << " you have been robotomized\n";	
}

void	RobotomyRequestForm::action() const
{
	std::cout << "** Drill noises **\n";
	if(std::rand() % 2 == 0)
		robotomize();
	else
		std::cout << "Failed to robotomize\n";
}
