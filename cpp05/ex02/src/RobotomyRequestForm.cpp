#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/AForm.hpp"

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

void	RobotomyRequestForm::robotomize()
{
	std::cout << "** Drill noises **\n" << this->target << " you have been robotomized\n";
	
}
