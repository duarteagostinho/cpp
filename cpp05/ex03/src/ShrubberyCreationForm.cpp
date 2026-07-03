# include "../inc/ShrubberyCreationForm.hpp"
# include "../inc/AForm.hpp"
# include <fstream>
# include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = Target;
}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src)
{
	this->target = src.target;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
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

void	ShrubberyCreationForm::createFile() const
{
	std::ofstream	file(target + "_shrubbery");

	if (!file) {
		std::cerr << "Cannot create " << target << "_shrubbery" << std::endl;
		return;
	}
	file << "    *            *\n";
    file << "   ***          ***\n";
    file << "  *****        *****\n";
    file << " *******      *******\n";
    file << "   |||          |||\n";
	std::cout << "File: " << target << "_shrubbery" << " has been created\n"; 
}

void	ShrubberyCreationForm::action() const
{
	createFile();
}

/* ************************************************************************** */
