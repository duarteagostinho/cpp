# include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"
# include <fstream>
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor" << std::endl;
	this->target = Target;
}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src)
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	this->target = src.target;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::createFile()
{
	std::ofstream	file(target + "_shrubbery");

	if (!file)
		std::cerr << "Cannot create " << target << "_shrubbery" << std::endl;
	file << "    *            *\n";
    file << "   ***          ***\n";
    file << "  *****        *****\n";
    file << " *******      *******\n";
    file << "   |||          |||\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */